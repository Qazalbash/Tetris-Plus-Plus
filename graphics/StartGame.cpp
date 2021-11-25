#include "StartGame.hpp"

//implementation of Start Game image on main screen

//Drawing the sprite(Start game)
void StartGame::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    if (rec_recover){
        moverRect.x= moverRect.x-5;
        moverRect.y=moverRect.y-5;
        rec_recover=false;
    }
}

//Picture moving to give effect of a button. 
void StartGame::animate(){
    rec_recover=true;
    moverRect.x=moverRect.x+5;
    moverRect.y=moverRect.y+5; 
}


//Construtor of Start Game
StartGame::StartGame(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {180,255, 140, 34};    

    // it will display Start Game icon on x = 400, y = 500 location, the size of start game is 200 width, 80 height
    moverRect = {400, 500, 200, 80};
}