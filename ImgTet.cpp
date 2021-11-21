#include "ImgTet.hpp"
// pigeon implementation will go here.

void ImgTet::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    // moverRect.x+=2; // moves the pigeon one pixel towards right, should it be in fly function??
}

ImgTet::ImgTet(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {176,90, 144, 95};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {370, 180, 270, 200};
}