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
    if ( moverRect.y+moverRect.h<=ground && movement==true){
        moverRect.y+=speed;
    }
}
//Function checks whether block has touched the ground. 
// bool Oplus::isReached(){
//     if (moverRect.y<400){
//         return false;
//     }
//     else{
//         return true;
//     }
// }

//rotates the tetris pieces by switching through the pieces. 
void Oplus::rotation(){
    if (rotater_no==0){
        srcRect = {151, 311, 44, 49};
    }
    else{
        srcRect = {151, 311, 44, 49};
    }
}

//moves Lplus piece to the left,right and down. 
void Oplus::slide(int direct){
    // 1 refers to moving the tetrimino to the right
    if (direct==1){
         if (moverRect.x<rightwall){
            moverRect.x+=right_mag;
        }  
    }
    // -1 refers to moving the tetrimino to the LEFT
    else if(direct==-1){
        if (moverRect.x>leftwall){
            moverRect.x-=left_mag;
        }
    }
    // 0 refers to moving the tetrimino to the bottom
    else if (direct ==0){
        moverRect.y=ground;
    }
}

// constructor of Lplus 
Oplus::Oplus(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {151, 311, 44, 49};   

    // it will display pigeon on x = 30, y = 40 location, the size of Lplus block is 100 width, 80 height
    moverRect = {300, 40, 50, 50};
}