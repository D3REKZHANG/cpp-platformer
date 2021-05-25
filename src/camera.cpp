#include "camera.h"
#include "raylib.h"
#include <iostream>

MyCamera::MyCamera(std::string m){
    mode = m;
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void MyCamera::update(Player p, int screenWidth, int screenHeight){

    float pCenterX = p.pos.x+p.rect.width;
    float pCenterY = p.pos.y+p.rect.height;

    if(mode == "follow"){
        if(pCenterX >= screenWidth/2 && pCenterX <= 1000){
            camera.target.x = pCenterX;
            camera.offset.x = screenWidth/2;
        }else{
            camera.target.x = 0;
            camera.offset.x = 0;
        }

        if(pCenterY <= 0 || pCenterY >= screenHeight){
            camera.target.y = pCenterY;
            camera.offset.y = screenHeight/2;
        }else{
            camera.target.y = 0;
            camera.offset.y = 0;
        }
    }
}



