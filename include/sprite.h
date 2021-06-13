#ifndef SPRITE_H
#define SPRITE_H

#include "raylib.h"
#include <vector>
#include <utility>

class Sprite{
    public:
        Texture2D spritesheet;
        int width, height;
        int framesCounter = 0;
        int framesSpeed = 8;
        int currentFrame;
        std::vector<std::pair<int, int>> frameRanges;
        std::pair<int, int> currentRange;
        Rectangle frameRec;

        Sprite(char *file, int w, int h);

        void update(int frameSpeed);
        void draw(Vector2 position);
};

#endif 
