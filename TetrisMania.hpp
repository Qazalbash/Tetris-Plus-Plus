#include<SDL.h>
#include "ImgTet.hpp"
#include "StartGame.hpp"
#include "Exit.hpp"
#include "game.hpp"
#include "Lplus.hpp"
#pragma once



class TetrisMania{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

    //Right now we're creating one pigeon, 
    // In the solution you have to create vectors of pigeons, eggs, and nests    
    ImgTet t1;
    StartGame sg;
    Exit ex;
    Game gm;
    Lplus L;
   

    public:
    TetrisMania(SDL_Renderer *, SDL_Texture *);
    void drawObjects(); 
    void createObject(int, int);
    void rotateObject();
    
};