#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "gamestate.h"

class Menu : public GameState {
    public:
        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(StateManager* SM);
        void update(StateManager* SM);
        void draw(StateManager* SM);

        static Menu* instance() {
            return &menu;
        }
    protected: 
        Menu(){}
    private: 
        static Menu menu;
};

#endif
