#include "TetrisMania.hpp"

bool TetrisMania::drawObjects()
{
    /*
    Moves shapes down and return true when grid is full
    */
    bool parity = gridLogic->moveShapeDown();
    // draw grids
    gridLogic->drawGrid(gRenderer, assets);
    // draw shape
    gridLogic->drawShapeGrid(gRenderer, assets);
    return parity;
}

void TetrisMania::drawMainScreenButtons()
{
    // First drawing Img Tet
    SDL_Rect sRect = {176, 90, 144, 95};
    SDL_Rect mRect = {370, 290, 270, 200};

    SDL_RenderCopy(gRenderer, assets, &sRect, &mRect);

    // Second drawing start Game
    sRect = {180, 255, 140, 34};
    mRect = {400, 726, 200, 80};

    SDL_RenderCopy(gRenderer, assets, &sRect, &mRect);

    // Third drawing the Exit button
    sRect = {3, 0, 93, 40};
    mRect = {15, 10, 125, 50};

    SDL_RenderCopy(gRenderer, assets, &sRect, &mRect);
}

bool TetrisMania::isReached()
{
    return false;
}

// generates random blocks.
void TetrisMania::randomBlock() {}

// Function used to rotate individual blocks.
void TetrisMania::rotateShape()
{
    ~*gridLogic;
    SDL_Delay(50);
}

void TetrisMania::moveeShapeLeft()
{
    gridLogic->moveShapeLeft();
    SDL_Delay(50);
}

void TetrisMania::moveShapeRight()
{
    gridLogic->moveShapeRight();
    SDL_Delay(50);
}

// Function used tomove block to the left and right.
void TetrisMania::slideShapeDown()
{
    while (gridLogic->moveShapeDown())
    {
    }
}

TetrisMania::TetrisMania(SDL_Renderer *gr, SDL_Texture *asset, const int r, const int c) : gRenderer(gr), assets(asset)
{
    gridLogic = new GridLogic(r, c);
}