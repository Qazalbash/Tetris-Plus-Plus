#include "GridLogic.hpp"

GridLogic::GridLogic(const int R, const int C)
{
    /*
    Initializing grid and shape grid as one dimensional array with 0 values
    */

    ROWS = R;
    COLS = C;

    grid = new int[R * C];
    shape_grid = new int[SHAPE_COLS * SHAPE_ROWS];

    initGrid();

    // selecting shape

    selectShape();

    // the required rectangles for printing the grid
    srcRect = {244, 384, 33, 33};
    moverRect = {0, 0, 25, 25};

    shapeBaseRect = {baseX + int(C / 2) * 25, 0, 25, 25};

    groundY = baseY + (R * 25) - 125; // subtraction 125 because shape size is 125*125
}

void GridLogic::initShapeGrid()
/*
Initializes the shapegrid as 0 values
*/
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            *(shape_grid + i * SHAPE_COLS + j) = 0;
        }
    }
    shapeBaseRect = {baseX + int(COLS / 2) * 25, 0, 25, 25};
}

void GridLogic::initGrid()
/*
Initializes the grid as 0 values
*/
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(grid + i * COLS + j) = 0;
        }
    }
}

void GridLogic::drawGrid(SDL_Renderer *gRenderer, SDL_Texture *assets)
/*
This function itterates over grid and creates a single block where it is 1.
*/
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int value = *(grid + i * COLS + j);

            if (value == 1)
            {
                moverRect.y = baseY + (25 * i);
                moverRect.x = baseX + (25 * j);
                SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
            }
        }
    }
}

void GridLogic::drawShapeGrid(SDL_Renderer *gRenderer, SDL_Texture *assets)
/*
This function itterates over shapegrid and creates a single block where it is 1.
It translates the squares by moverRect vector.
*/
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            int value = *(shape_grid + i * SHAPE_COLS + j);

            if (value == 1)
            {
                moverRect.y = shapeBaseRect.y + (25 * i);
                moverRect.x = shapeBaseRect.x + (25 * j);
                SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
            }
        }
    }
}

bool GridLogic::moveShapeDown()
{
    int shapeBottomIndex = 0; // the index of the first one from the bottom side
    for (int i = SHAPE_ROWS * SHAPE_COLS - 1; i >= 0; i--)
    {
        if (*(shape_grid + i) == 1)
        {
            shapeBottomIndex = i; // index of the most bottom block
            break;
        }
    }

    int shapeBottomPixels = 25 * (4 - int(shapeBottomIndex / 5));

    if ((shapeBaseRect.y + 25) <= (groundY + shapeBottomPixels) && !isCollidingDown())
    // shape is not colliding and also above the ground keep it moving
    {
        shapeBaseRect.y += 25;
        return true;
    }
    else
    // update the grid and make the current scene as a part of the gird, and select new shape
    {
        updateGrid();
        selectShape();
        return false;
    }
}

void GridLogic::selectShape()
/*
initialize the shapegrid and randomly selects shape and populate the grid
*/
{
    initShapeGrid();
    srand((unsigned)time(0));
    int secretNumber = rand() % 7;

    switch (secretNumber)
    {
    case 0:
        makeShapeI();
        break;
    case 1:
        makeShapeT();
        break;
    case 2:
        makeShapeJ();
        break;
    case 3:
        makeShapeL();
        break;
    case 4:
        makeShapeO();
        break;
    case 5:
        makeShapeS();
        break;
    case 6:
        makeShapeZ();
        break;
    }
}

void GridLogic::updateGrid()
// This function itterates over shapegrid and write 1 on grid, translated by moverRect vector.
{
    // writing the shape to grid
    int shapeCoord = 0;
    for (int i = ((shapeBaseRect.y - baseY) / 25); i < ((shapeBaseRect.y - baseY) / 25) + SHAPE_ROWS; i++)
    {
        for (int j = ((shapeBaseRect.x - baseX) / 25); j < ((shapeBaseRect.x - baseX) / 25) + SHAPE_COLS; j++)
        {
            int shapeValue = *(shape_grid + shapeCoord);
            shapeCoord++;

            if (shapeValue == 1)
            {
                *(grid + i * COLS + j) = 1;
            }
        }
    }

    // checing if any row in the grid is full
    bool flag = false;
    for (int i = 0; i < ROWS; i++)
    {
        flag = true;
        for (int j = 0; j < COLS; j++)
        {
            flag = *(grid + i * COLS + j);
            if (!flag)
            // if any row has any 0 this loop will break and the we will check one above of it
            {
                break;
            }
        }
        if (flag)
        // if there is a row full of 1s it will be removed
        {
            removeGridRow(i);
            i--;
        }
    }
}

void GridLogic::removeGridRow(int rowIndex)
// removes an entire row from the grid
{
    int prevJindex; // previous row index
    for (int i = rowIndex; i >= 0; i--)
    {
        for (int j = 0; j < COLS; j++)
        {
            prevJindex = (i - 1) * COLS + j;                                           // previous row index
            *(grid + i * COLS + j) = (prevJindex >= 0) * *(grid + (i - 1) * COLS + j); // setting next row value as previous row value
        }
    }
}

bool GridLogic::isCollidingDown()
// return true when two blocks are colliding
{
    int shapeCoord = 0;
    for (int i = ((shapeBaseRect.y - baseY) / 25); i < ((shapeBaseRect.y - baseY) / 25) + SHAPE_ROWS; i++)
    {
        for (int j = ((shapeBaseRect.x - baseX) / 25); j < ((shapeBaseRect.x - baseX) / 25) + SHAPE_COLS; j++)
        {
            int shapeValue = *(shape_grid + shapeCoord); // block square value
            shapeCoord++;

            int gridValue = *(grid + (i + 1) * COLS + j); // very next square from block

            if (shapeValue == 1 && gridValue == 1)
            // if the shape and grid is 1 then returns true
            {
                return true;
            }
        }
    }
    return false;
}

bool GridLogic::isCollidingRight()
// returns true if shape is colliding on right with other blocks or the right most walls
{
    int shapeCoord = 0;
    for (int i = ((shapeBaseRect.y - baseY) / 25); i < ((shapeBaseRect.y - baseY) / 25) + SHAPE_ROWS; i++)
    {
        for (int j = ((shapeBaseRect.x - baseX) / 25); j < ((shapeBaseRect.x - baseX) / 25) + SHAPE_COLS; j++)
        {
            int shapeValue = *(shape_grid + shapeCoord);
            shapeCoord++;

            if (shapeValue == 1 && j + 1 == COLS) // if the shape is already at the right most corner
            {
                return true;
            }

            int gridValue = *(grid + i * COLS + (j + 1));

            if (shapeValue == 1 && gridValue == 1) // if shape is colliding with other blocks
            {
                return true;
            }
        }
    }
    return false;
}

bool GridLogic::isCollidingLeft()
// returns true if shape is colliding on right with other blocks or the left most walls
{
    int shapeCoord = 0;
    for (int i = ((shapeBaseRect.y - baseY) / 25); i < ((shapeBaseRect.y - baseY) / 25) + SHAPE_ROWS; i++)
    {
        for (int j = ((shapeBaseRect.x - baseX) / 25); j < ((shapeBaseRect.x - baseX) / 25) + SHAPE_COLS; j++)
        {
            int shapeValue = *(shape_grid + shapeCoord);
            shapeCoord++;

            if (shapeValue == 1 && j == 0) // if the shape is already at the left most corner
            {
                return true;
            }

            int gridValue = *(grid + i * COLS + (j - 1));

            if (shapeValue == 1 && gridValue == 1) // if shape is colliding with other blocks
            {
                return true;
            }
        }
    }
    return false;
}

void GridLogic::makeShapeI()
// making the shape I, setting grid 1 on the places where it makes the required shape
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            // turing shape grid 1 at the logic on right hand side
            *(shape_grid + i * SHAPE_COLS + j) = (j == 2);
        }
    }
}

void GridLogic::makeShapeT()
// making the shape T, setting grid 1 on the places where it makes the required shape
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            // turing shape grid 1 at the logic on right hand side
            *(shape_grid + i * SHAPE_COLS + j) = ((i == 1 && j == 2) || (i == 2 && (j == 1 || j == 2 || j == 3)));
        }
    }
}

void GridLogic::makeShapeJ()
// making the shape J, setting grid 1 on the places where it makes the required shape
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            // turing shape grid 1 at the logic on right hand side
            *(shape_grid + i * SHAPE_COLS + j) = ((i == 1 && j == 1) || (i == 2 && (j == 1 || j == 2 || j == 3)));
        }
    }
}

void GridLogic::makeShapeL()
// making the shape L, setting grid 1 on the places where it makes the required shape
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            // turing shape grid 1 at the logic on right hand side
            *(shape_grid + i * SHAPE_COLS + j) = ((i == 1 && j == 3) || (i == 2 && (j == 1 || j == 2 || j == 3)));
        }
    }
}

void GridLogic::makeShapeO()
// making the shape O, setting grid 1 on the places where it makes the required shape
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            // turing shape grid 1 at the logic on right hand side
            *(shape_grid + i * SHAPE_COLS + j) = ((i == 1 || i == 2) && (j == 1 || j == 2));
        }
    }
}

void GridLogic::makeShapeS()
// making the shape S, setting grid 1 on the places where it makes the required shape
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            // turing shape grid 1 at the logic on right hand side
            *(shape_grid + i * SHAPE_COLS + j) = (((i == 1 || i == 2) && j == 2) || (i == 1 && j == 3) || (i == 2 && j == 1));
        }
    }
}

void GridLogic::makeShapeZ()
// making the shape Z, setting grid 1 on the places where it makes the required shape
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            // turing shape grid 1 at the logic on right hand side
            *(shape_grid + i * SHAPE_COLS + j) = (((i == 1 || i == 2) && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 3));
        }
    }
}

void GridLogic::operator~()
// rotates the shape when being called
{
    int *temp = new int[SHAPE_COLS * SHAPE_ROWS];
    for (int blockRowArrow = 0; blockRowArrow < SHAPE_ROWS; blockRowArrow++)
    {
        for (int blockColArrow = 0; blockColArrow < SHAPE_COLS; blockColArrow++)
        {
            temp[(blockColArrow * SHAPE_COLS) + SHAPE_ROWS - 1 - blockRowArrow] = shape_grid[blockRowArrow * SHAPE_COLS + blockColArrow];
        }
    }
    delete shape_grid;
    shape_grid = temp;
}

void GridLogic::moveShapeLeft()
{
    // here check first if it collides to the left side
    if (!isCollidingLeft())
    {
        shapeBaseRect.x -= 25;
    }
}

void GridLogic::moveShapeRight()
{
    // check first if it collide to the right side
    if (!isCollidingRight())
    {
        shapeBaseRect.x += 25;
    }
}
