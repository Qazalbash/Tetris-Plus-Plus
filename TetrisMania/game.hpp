
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Grid.cpp"
#include <SDL_ttf.h>

#include "TetrisMania.hpp"
#include <vector>
#include <fstream>
#include <SDL_mixer.h>

using namespace std;


class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    string cur_string = " ";
    

public:
    bool check=false;
    bool blit_called;
    void blit();
    bool init();
    bool loadMedia(bool check);
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    void Score(string s);
    sdl_grid G [25][15];
    void Generate_Grid();  

};

