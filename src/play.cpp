#include "../include/raylib.h"
#include "../include/gamestate.h"
#include "../include/statemanager.h"
#include "../include/play.h"
#include "../include/menu.h"
#include "../include/player.h"

Play Play::play;

void Play::init(){}

void Play::cleanup(){}
 
void Play::pause(){}
void Play::resume(){}

void Play::handleEvents(StateManager* SM){}

void Play::update(StateManager* SM){
    p.update();
}

void Play::draw(StateManager* SM){
    ClearBackground(WHITE);
    DrawText("play",10,10,50,RED);
    p.draw();
}
