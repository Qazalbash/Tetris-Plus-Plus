#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class GridLogic
{
private:
    int ROWS;
    int COLS;
    int SHAPE_COLS = 5;
    int SHAPE_ROWS = 5;

    const int baseX = 125; // the x coordinate from where the grid is drawn
    const int baseY = 50;  // the y coordinate from where the grid is drawn

    int groundY;

    SDL_Rect srcRect;
    SDL_Rect moverRect;

    SDL_Rect shapeBaseRect;

    int *grid;
    int *shape_grid;

public:
    GridLogic(const int R, const int C);

    void initShapeGrid();
    void printShapeGrid();
    void initGrid();
    void printGrid();

    void drawGrid(SDL_Renderer *gRenderer, SDL_Texture *assets);
    void drawShapeGrid(SDL_Renderer *gRenderer, SDL_Texture *assets);

    bool moveShapeDown();
    void updateGrid();
    void removeGridRow(int rowIndex);

    bool isCollidingDown();
    bool isCollidingRight();
    bool isCollidingLeft();

    void makeShapeI();
    void makeShapeT();
    void makeShapeJ();
    void makeShapeL();
    void makeShapeO();
    void makeShapeS();
    void makeShapeZ();

    void selectShape();

    void rotateShape();
    void moveShapeLeft();
    void moveShapeRight();
};