#include "Tplus.hpp"
#include <iostream>
using namespace std;

// Tplus(tetris block in the shape of a T) implementation.
void Tplus::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    drop(); 
}

// moves the tetrimino one pixel towards down.
void Tplus::drop(){
    if (moverRect.y<ground && movement==true){
        moverRect.y+=speed;
    }
}

//Function checking whether function has touched the ground. 
// bool Tplus::isReached(){
//     if (moverRect.y<400){
//         return false;
//     }
//     else{
//         return true;
//     }
// }

//rotates the tetris pieces by switching through the pieces. 
void Tplus::rotation(){
    if (n==0){
        srcRect = {155,450, 62, 44};
        n++;
    }
    else if (n==1){
        srcRect = {413,432, 43, 63};
        n++;
    }
    else if(n==2){
        srcRect = {269,431, 62, 43};
        n=0;
    }
}

//moves Tplus piece to the left,right and down. 
void Tplus::slide(int direct){
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
Tplus::Tplus(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {25,436, 44, 63};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {300, 40, 100, 80};
}