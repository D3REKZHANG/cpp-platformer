#include "../include/raylib.h"
#include "../include/gamestate.h"
#include "../include/statemanager.h"
#include "../include/play.h"
#include "../include/menu.h"
#include "../include/player.h"
#include "../include/block.h"

#include <iostream>
#include <string>

Play Play::play;

void Play::init(){
    gravity = 2;
    blockList.push_back(Block({10,480,700,10}, RED));
    blockList.push_back(Block({500,450,200,40}, RED));
    blockList.push_back(Block({300,350,100,30}, RED));

    // camera setup
    // camera.rotation = 0.0f;
    // camera.zoom = 1.0f;
}

void Play::handleEvents(StateManager* SM){
    p.handleEvents();
}

void Play::update(StateManager* SM){
    p.update(gravity);
    
    p.grounded = false;
    std::printf("Before: (%f,%f)\n", p.pos.x, p.pos.y);
    // collision checking
    for(Block block:blockList){
        // check y-axis collision
        if(CheckCollisionRecs(p.rect, block.rect)){
            if(p.prev.y+p.rect.height < block.rect.y){
                p.pos.y = block.rect.y-p.rect.height;
                // ground the player
                p.vel.y = 0;
                p.grounded = true;
            }else if(p.prev.y > block.rect.y+block.rect.height){
                p.pos.y = block.rect.y+block.rect.height;
            }
        }
        p.refreshRect();
            
        // if still colliding
        if(CheckCollisionRecs(p.rect, block.rect)){
            if(p.prev.x+p.rect.width < block.rect.x){
                p.pos.x = block.rect.x-p.rect.width;
                p.vel.x = 0;
            }else if(p.prev.x > block.rect.x+block.rect.width){
                p.pos.x = block.rect.x+block.rect.width;
            }
        }

        p.refreshRect();
    }
    std::printf("After: (%f,%f)\n", p.pos.x, p.pos.y);

    /*
    camera.target = {p.rect.x+p.rect.width/2, p.rect.y+p.rect.height/2};
    camera.offset.x = (p.rect.x > 800/2) ? 800/2.0f : 0;
    camera.offset.y = (p.rect.y > 500/2) ? 500/2.0f : 0;
    */
}

void Play::draw(StateManager* SM){
    ClearBackground(WHITE);

    DrawText("play",10,10,50,RED);
    DrawText(std::to_string(GetFPS()).c_str(),300,10,20,BLACK);

    //BeginMode2D(camera);
        // draw blocks
        for(Block block:blockList){
            block.draw();
        }

        p.draw();
    //EndMode2D();
}

// unused functions
void Play::cleanup(){}
 
void Play::pause(){}
void Play::resume(){}
