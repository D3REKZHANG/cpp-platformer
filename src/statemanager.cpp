#include "../include/raylib.h"
#include "../include/statemanager.h"
#include "../include/gamestate.h"

void StateManager::cleanup(){
    while (!states.empty()) {
        states.back()->cleanup();
        states.pop_back();
    }
}

void StateManager::changeState(GameState* state){
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->cleanup();
        states.pop_back();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->init();
}

void StateManager::pushState(GameState* state){
    // pause current state
    if ( !states.empty() ) {
        states.back()->pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->init();
}

void StateManager::popState(GameState* state){
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->cleanup();
        states.pop_back();
    }

    // resume previous state
    if ( !states.empty() ) {
        states.back()->resume();
    }
}

void StateManager::handleEvents(){
    states.back()->handleEvents(this);
}

void StateManager::update(){
    states.back()->update(this);
}

void StateManager::draw(){
    states.back()->draw(this);
}

bool StateManager::running(){ 
    return isRunning; 
}

bool StateManager::quit(){ 
    isRunning = false;
    return true;
}
