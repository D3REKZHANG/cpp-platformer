#ifndef PLAY_H
#define PLAY_H

#include "raylib.h"
#include "gamestate.h"
#include "player.h"
#include "block.h"
#include <vector>

class Play : public GameState {
    private: 
        static Play play;
    protected: 
        Play(){}
    public:
        std::vector<Block> blockList;
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
