#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player{
    public:
        Vector2 pos, vel, acc;
        bool grounded;
        Rectangle rect;

        Player(Vector2 _pos);
        void refreshRect();
        float bottom();
        void handleEvents();
        void update(float gravity);
        void draw();
};

#endif 
