#include<SDL.h>
#pragma once


//Parent class of block.All shapes are inherited from this main class. 
//contains all common functions for the different shapes. 
class Tetris_Block{

public:
    // add the fly function here as well.
    virtual void draw(SDL_Renderer*, SDL_Texture* assets)=0;
    virtual void drop()=0;
    virtual void rotation()=0;
    virtual void slide(int)=0;
    void isReached(bool b){
        movement=b;
    }
    SDL_Rect getmover(){
        return moverRect;
    }
protected:
    SDL_Rect srcRect, moverRect;
    int rotater_no=0;
    int speed = 10;
    float right_mag = 12.5;
    float left_mag = 12.5;
    bool movement=true;
    static const int ground = 480;
    

     
};
