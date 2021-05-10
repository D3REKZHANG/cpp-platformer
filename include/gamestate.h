#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "statemanager.h"

class GameState{
    public:
        virtual void init();
        virtual void cleanup();

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void handleEvents(StateManager* sm) = 0;
        virtual void update(StateManager* sm) = 0;
        virtual void draw(StateManager* sm) = 0;

        void changeState(StateManager* sm, GameState* state){
            sm->changeState(state);
        }
    protected:
        GameState(){}
};

#endif
