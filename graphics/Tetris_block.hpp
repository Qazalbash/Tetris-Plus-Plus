#include<SDL.h>
#pragma once


//Parent class of block.All shapes are inherited from this main class. 
//contains all common functions for the different shapes. 
class Tetris_Block{
SDL_Rect srcRect, moverRect;
int n=0;
public:
    // add the fly function here as well.
    virtual void draw(SDL_Renderer*, SDL_Texture* assets)=0;
    virtual void drop()=0;
    virtual void rotation()=0;
    virtual void slide(int)=0;
    virtual bool isReached()=0;
     
};
