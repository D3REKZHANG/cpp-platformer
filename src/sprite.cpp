#include "../include/raylib.h"
#include "../include/sprite.h"

#include <string.h>

Sprite::Sprite(char *file, int w, int h){
	spritesheet = LoadTexture(strcat("../resources/",file));
	width = w;
	height = h;
}

void Sprite::update(int framesSpeed){
	framesCounter++;

	if (framesCounter >= (60/framesSpeed))
	{
		framesCounter = 0;
		currentFrame++;

		if (currentFrame > currentRange.second) currentFrame = currentRange.first;

		frameRec.x = (float)currentFrame*(float)width;
	}
}

void Sprite::draw(Vector2 position){
	DrawTextureRec(spritesheet, frameRec, position, WHITE);
}


