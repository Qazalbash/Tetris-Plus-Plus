#include<SDL.h>
#include "ImgTet.hpp"
#include "StartGame.hpp"
#include "Exit.hpp"
#include "game.hpp"
#include "Lplus.hpp"
#include "Tplus.hpp"
#include "Oplus.hpp"
#include "MyVector.cpp"

#pragma once



class TetrisMania{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

    // initializing obkects to print sprites on main screen 
    int screen_number=0;
    ImgTet t1;
    StartGame sg;
    Exit ex;
    Game gm;

    //Vector used to hold the random blocks that are generated. 
    MyVector<Tetris_Block*> Blocks;
    Tetris_Block *currentblock;

    public:
    TetrisMania(SDL_Renderer *, SDL_Texture *);
    void drawObjects(); 
    void createObject(int, int);
    void rotateObject();
    void slideObject(int);
    Tetris_Block* randomBlock();
    void screen_Setter(int );
    
};