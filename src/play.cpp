#include "../include/raylib.h"
#include "../include/gamestate.h"
#include "../include/statemanager.h"
#include "../include/play.h"
#include "../include/menu.h"
#include "../include/player.h"

Play Play::play;

void Play::handleEvents(StateManager* SM){}

void Play::update(StateManager* SM){
    p.update();
}

void Play::draw(StateManager* SM){
    ClearBackground(WHITE);

    // draw blocks
    for(int r=0;r<10;r++){
        for(int c=0;c<16;c++){
            if(blocks[r][c] == 1) DrawRectangle(c*50, r*50, 50, 50, RED);
        }
    }

    DrawText("play",10,10,50,RED);
    p.draw();
}

// unused functions
void Play::init(){}

void Play::cleanup(){}
 
void Play::pause(){}
void Play::resume(){}
