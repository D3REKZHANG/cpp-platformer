#ifndef PLAY_H
#define PLAY_H

#include "raylib.h"
#include "gamestate.h"
#include "player.h"

class Play : public GameState {
    private: 
        static Play play;
    protected: 
        Play(){}
    public:
        int blocks[10][16] = {
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0},
            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}
        };
        Player p{(Vector2){200,200}};

        // default methods
        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(StateManager* SM);
        void update(StateManager* SM);
        void draw(StateManager* SM);

        static Play* instance() {
            return &play;
        }
};

#endif
