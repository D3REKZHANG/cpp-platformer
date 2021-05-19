#include "../include/raylib.h"
#include "../include/player.h" 

Player::Player(Vector2 _pos){
    pos = _pos;
    prevPos = _pos;
    vel = (Vector2){0,0};
    canJump = false;
    falling = true;
}

void Player::refreshRect(){
    rect = {pos.x, pos.y, 40, 40};
}

void Player::update(){
    if (IsKeyDown(KEY_RIGHT)) 
        vel.x = 12.0f;
    else if (IsKeyDown(KEY_LEFT)) 
        vel.x = -12.0f;
    else 
        vel.x = 0;
    
    if(falling) 
        vel.y = 10;
    else
        vel.y = 0;

    pos.x += vel.x;
    pos.y += vel.y;
    refreshRect();
}

void Player::draw(){
    DrawRectangleRec(rect, BLUE);
}
