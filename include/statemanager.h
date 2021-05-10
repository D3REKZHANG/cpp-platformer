#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <bits/stdc++.h>

class GameState;

class StateManager {
    private:
        std::vector<GameState*> states;
        bool isRunning = true;
    public:
        void init();
        void cleanup();

        void changeState(GameState* state);
        void pushState(GameState* state);
        void popState(GameState* state);

        void handleEvents();
        void update();
        void draw();

        bool running();
        bool quit();
};

#endif
