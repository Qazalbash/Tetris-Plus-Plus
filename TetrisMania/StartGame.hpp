#include<SDL.h>
#pragma once


// Used to import image of Start Game from assets.png
class StartGame{
SDL_Rect srcRect, moverRect;
bool rec_recover=false;

public:
    //Functions  used to draw and move picture to look like a button. 
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void animate();
    
    StartGame();  

};
