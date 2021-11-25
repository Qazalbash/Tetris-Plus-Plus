#include<SDL.h>
#include "Tetris_block.hpp"
#pragma once

class Tplus:public Tetris_Block{
SDL_Rect srcRect, moverRect;
int n=0;
public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void drop();
    void rotation();
    void slide(int);
    bool isReached();
    Tplus(); // may add other overloaded constructors here... 
};
