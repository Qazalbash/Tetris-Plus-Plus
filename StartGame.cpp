#include "StartGame.hpp"
// pigeon implementation will go here.

void StartGame::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    if (rec_recover){
        moverRect.x= moverRect.x-5;
        moverRect.y=moverRect.y-5;
        rec_recover=false;
    }
    // moverRect.x+=2; // moves the pigeon one pixel towards right, should it be in fly function??
}

void StartGame::animate(){
    rec_recover=true;
    moverRect.x=moverRect.x+5;
    moverRect.y=moverRect.y+5; 
}


StartGame::StartGame(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {180,255, 140, 34};    

    // it will display Start Game icon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {400, 500, 200, 80};
}