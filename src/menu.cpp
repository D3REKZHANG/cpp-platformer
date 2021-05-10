#include "../include/raylib.h"
#include "../include/gamestate.h"
#include "../include/statemanager.h"
#include "../include/menu.h"
#include "../include/play.h"

Menu Menu::menu;

void Menu::init(){}
void Menu::cleanup(){}

void Menu::pause(){}
void Menu::resume(){}

void Menu::handleEvents(StateManager* SM){
    if(IsKeyReleased(' ')){
        SM->changeState(Play::instance());
    }
}

void Menu::update(StateManager* SM){}

void Menu::draw(StateManager* SM){
    ClearBackground(WHITE);
    DrawText("menu", 10,10,50,BLUE);
}
