#pragma once
#include <SDL.h>
#include "GridLogic.hpp"
#include <iostream>

using namespace std;

class TetrisMania
{

    GridLogic *gridLogic;

    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

public:
    TetrisMania(SDL_Renderer *gr, SDL_Texture *asset, const int r, const int c);
    bool drawObjects();

    void slideShapeDown();
    void randomBlock();
    bool isReached();
    void drawMainScreenButtons();
    void rotateShape();
    void moveShapeRight();
    void moveeShapeLeft();

    void printGrid();
};