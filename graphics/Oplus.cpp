#include "Oplus.hpp"
#include <iostream>
using namespace std;

// Lplus implementation will go here.
void Oplus::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    drop(); 
}

// moves the tetrimino one pixel towards down.
void Oplus::drop(){
    int ground =400;
    if (moverRect.y<ground){
        moverRect.y+=4;
    }
}
//Function checks whether block has touched the ground. 
bool Oplus::isReached(){
    if (moverRect.y<400){
        return false;
    }
    else{
        return true;
    }
}

//rotates the tetris pieces by switching through the pieces. 
void Oplus::rotation(){
    if (n==0){
        srcRect = {277,185, 43, 61};
        n++;
    }
    else if (n==1){
        srcRect = {149,210, 63, 44};
        n++;
    }
    else if(n==2){
        srcRect = {393,327, 42, 64};
        n=0;
    }
}

//moves Lplus piece to the left,right and down. 
void Oplus::slide(int direct){
    // 1 refers to moving the tetrimino to the right
    if (direct==1){
    moverRect.x+=5;
    }
    // 1 refers to moving the tetrimino to the LEFT
    else if(direct==-1){
        moverRect.x-=5;
    }
    // 1 refers to moving the tetrimino to the bottom
    else if (direct ==0){
        moverRect.y=400;
    }
}

// constructor of Lplus 
Oplus::Oplus(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {17, 201, 63, 43};

    // it will display pigeon on x = 30, y = 40 location, the size of Lplus block is 100 width, 80 height
    moverRect = {370, 40, 100, 80};
}