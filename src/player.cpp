#include "../include/raylib.h"
#include "../include/player.h" 
#include<bits/stdc++.h>

Player::Player(Vector2 _pos){
    pos = _pos;
    vel = (Vector2){0,0};
    canJump = false;
}

void Player::update(){
    if (IsKeyDown(KEY_RIGHT)) 
        vel.x = 12.0f;
    else if (IsKeyDown(KEY_LEFT)) 
        vel.x = -12.0f;
    else 
        vel.x = 0;

    if (IsKeyDown(KEY_UP)) 
        vel.y = -12.0f;
    else if (IsKeyDown(KEY_DOWN)) 
        vel.y = 12.0f;
    else 
        vel.y = 0;

    pos.x += vel.x;
    pos.y += vel.y;
}

void Player::draw(){
    rect = {pos.x, pos.y, 40, 40};
    DrawRectangleRec(rect, BLUE);
}
