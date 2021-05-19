#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player{
    public:
        Vector2 pos;
        Vector2 prevPos;
        Vector2 vel;
        bool canJump;
        bool falling;
        Rectangle rect;

        Player(Vector2 _pos);
        void refreshRect();
        void update();
        void draw();
};

#endif 
