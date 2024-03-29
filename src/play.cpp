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
    blockList.push_back(Block({200,350,100,20}, RED));
    blockList.push_back(Block({300,360,100,30}, RED));
}

void Play::handleEvents(StateManager* SM){
    p.handleEvents();
}

void Play::update(StateManager* SM){
    p.update(gravity);
    
    p.grounded = false;

    // collision checking
    for(Block block:blockList){
        // check y-axis collision
        if(CheckCollisionRecs(p.rect, block.rect)){
            if(p.prev.y+p.rect.height <= block.rect.y){
                p.pos.y = block.rect.y-p.rect.height;
                p.grounded = true;
                p.vel.y = 0;
            }else if(p.prev.y >= block.rect.y+block.rect.height){
                p.pos.y = block.rect.y+block.rect.height;
                p.vel.y = 0;
            }
            p.refreshRect();
        }
            
        // if still colliding on x-axis
        if(CheckCollisionRecs(p.rect, block.rect)){
            if(p.prev.x+p.rect.width <= block.rect.x){
                p.pos.x = block.rect.x-p.rect.width;
                p.vel.x = 0;
            }else if(p.prev.x >= block.rect.x+block.rect.width){
                p.pos.x = block.rect.x+block.rect.width;
                p.vel.x = 0;
            }
            p.refreshRect();
        }

    }

    camera.update(p, 800, 500);
}

void Play::draw(StateManager* SM){
    ClearBackground(WHITE);

    DrawText("play",10,10,50,RED);
    DrawText(std::to_string(GetFPS()).c_str(),300,10,20,BLACK);

    BeginMode2D(camera.camera);
        // draw blocks
        for(Block block:blockList){
            block.draw();
        }

        p.draw();
    EndMode2D();
}

// unused functions
void Play::cleanup(){}
 
void Play::pause(){}
void Play::resume(){}
