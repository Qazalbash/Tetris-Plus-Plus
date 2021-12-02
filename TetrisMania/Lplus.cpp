#include "Lplus.hpp"
#include <iostream>
using namespace std;

/* 
Lplus implementation will go here.
*/
void Lplus::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    drop(); 
}

// moves the tetrimino one pixel towards down.
void Lplus::drop(){
    if (moverRect.y<ground && movement==true){
        moverRect.y+=speed;
    }
}
//Function checks whether block has touched the ground. 
// bool Lplus::isReached(bool movement){
//     if (moverRect.y<ground){
//         return false;
//     }
//     else{
//         return true;
//     }    
// }

//rotates the tetris pieces by switching through the pieces. 
void Lplus::rotation(){
    if (rotater_no==0){
        srcRect = {155,450, 62, 44};
        rotater_no++;
    }
    else if (rotater_no==1){
        srcRect = {413,432, 43, 63};
        rotater_no++;
    }
    else if(rotater_no==2){
        srcRect = {269,431, 62, 43};
        rotater_no=0;
    }
}

//moves Lplus piece to the left,right and down. 
void Lplus::slide(int direct){
    // 1 refers to moving the tetrimino to the right
    if (direct==1){
    moverRect.x+=right_mag;
    }
    // 1 refers to moving the tetrimino to the LEFT
    else if(direct==-1){
        moverRect.x-=left_mag;
    }
    // 1 refers to moving the tetrimino to the bottom
    else if (direct ==0){
        moverRect.y=ground;
    }
   
}

/*
    constructor of Lplus
*/  
Lplus::Lplus(){
    //src coorinates from assets.png file, they have been found using spritecow.com
    //coordinates for entire block
    srcRect = {17, 201, 63, 43};

    // it will display pigeon on x = 30, y = 40 location, the size of Lplus block is 100 width, 80 height
    moverRect = {310, 20, 75, 75};
    
   
}