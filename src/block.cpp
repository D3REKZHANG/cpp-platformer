#include "../include/block.h"
#include "raylib.h"

Block::Block(Rectangle _rect, Color _col){
    rect = _rect;
    color = _col;
}


void Block::draw(){
    DrawRectangleRec(rect, color);
}
