#include "../include/raylib.h"
#include "../include/player.h" 

#include <algorithm>

Player::Player(Vector2 _pos){
    pos = _pos;
    vel = {0,0};
    acc = {0,0};
    grounded = true;
}

void Player::refreshRect(){
    rect = {pos.x, pos.y, 40, 40};
}

float Player::bottom(){
    return rect.x+rect.height;
}

void Player::handleEvents(){
    if (IsKeyDown(KEY_RIGHT)) 
        vel.x = 12.0f;
    else if (IsKeyDown(KEY_LEFT)) 
        vel.x = -12.0f;
    else 
        vel.x = 0;

    if(IsKeyPressed(KEY_UP)){
        if(grounded){
            vel.y = -20;
        }
    }
}

void Player::update(float gravity){
    acc.y = gravity;
    
    // apply position += velocity += acceleration
    vel.x += acc.x;
    vel.y = std::min(vel.y+acc.y, 15.0f); // cap vel.y at 15
    pos.x += vel.x;
    pos.y += vel.y;

    refreshRect();
}

void Player::draw(){
    DrawRectangleRec(rect, BLUE);
}
