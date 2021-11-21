#include "Lplus.hpp"
#include <iostream>
using namespace std;
// pigeon implementation will go here.

void Lplus::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    moverRect.y+=4; // moves the pigeon one pixel towards right, should it be in fly function??
}

void Lplus::rotation(){
    if (n==0){
        srcRect = {54,65, 23, 28};
        n++;
    }
    else if (n==1){
        srcRect = {100,48, 16, 40};
        n++;
    }
    else if(n==2){
        srcRect = {142,139, 15, 41};
        n=0;
    }

}

Lplus::Lplus(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {7,59, 23, 28};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {370, 40, 100, 80};
}