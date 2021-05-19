#ifndef BLOCK_H
#define BLOCK_H

#include "raylib.h"

class Block{
    public:
        Rectangle rect;
        Color color;
        Block(Rectangle rect, Color col);
        void draw();
};

#endif 