#ifndef CAMERA_H
#define CAMERA_H

#include "raylib.h"
#include "player.h"
#include <string>

class MyCamera{
    public:
        Camera2D camera;
        std::string mode;
        
        MyCamera(std::string mode);
        void update(Player p, int screenWidth, int screenHeight);
};

#endif