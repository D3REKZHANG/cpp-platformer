#include "../include/raylib.h"
#include "../include/gamestate.h"
#include "../include/statemanager.h"
#include "../include/play.h"
#include "../include/menu.h"
#include "../include/player.h"
#include "../include/block.h"
#include <iostream>

Play Play::play;

void Play::init(){
    blockList.push_back(Block({50,300,400,50}, RED));
}

void Play::handleEvents(StateManager* SM){}

void Play::update(StateManager* SM){
    p.update();
    
    p.falling = true;
    // collision checking
    for(Block block:blockList){
        if(CheckCollisionRecs(p.rect, block.rect)){
            p.pos.y = block.rect.y-p.rect.height;
            p.refreshRect();
            p.falling = false;
        }
    }
}

void Play::draw(StateManager* SM){
    ClearBackground(WHITE);

    // draw blocks
    for(Block block:blockList){
        block.draw();
    }

    DrawText("play",10,10,50,RED);
    p.draw();
}

// unused functions
void Play::cleanup(){}
 
void Play::pause(){}
void Play::resume(){}
