#include "GridLogic.hpp"

GridLogic::GridLogic(const int R, const int C)
{

    ROWS = R;
    COLS = C;

    grid = new int[R * C];
    shape_grid = new int[SHAPE_COLS * SHAPE_ROWS];

    // tetromino = new I(shape_grid);

    initGrid();
    printGrid();

    initShapeGrid();
    printShapeGrid();
    makeShapeI();

    // the required rectangles for printing the grid
    srcRect = {244, 384, 33, 33};
    moverRect = {0, 0, 25, 25};

    shapeBaseRect = {baseX + int(C / 2) * 25, 0, 25, 25};

    groundY = baseY + (R * 25) - 125; // subtraction 125 because shape size is 125*125
}

void GridLogic::initShapeGrid()
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

void GridLogic::printShapeGrid()
{
    cout << "\nPrinting Grid" << endl;
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            cout << *(shape_grid + i * SHAPE_COLS + j) << " ";
        }

        cout << endl;
    }

    cout << "--------------" << endl;
}

void GridLogic::initGrid()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(grid + i * COLS + j) = 0;
        }
    }
}

void GridLogic::printGrid()
{
    cout << "\nPrinting Grid" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << *(grid + i * COLS + j) << " ";
        }

        cout << endl;
    }

    cout << "--------------" << endl;
}

void GridLogic::drawGrid(SDL_Renderer *gRenderer, SDL_Texture *assets)
{

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // cout << *(grid + (i * COLS) + j) << " ";
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
{

    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            // cout << *(grid + (i * COLS) + j) << " ";
            int value = *(shape_grid + i * SHAPE_COLS + j);

            if (value == 1)
            {
                moverRect.y = shapeBaseRect.y + (25 * i); // baseY + (25 * i);
                moverRect.x = shapeBaseRect.x + (25 * j);
                SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
            }
        }
    }
    // shapeBaseRect.y += 25;
}

bool GridLogic::moveShapeDown()
{
    cout << "Shape Base Y: " << shapeBaseRect.y << endl;
    cout << "Ground Y: " << groundY << endl;

    int shapeBottomIndex = 0; // the index of the first one from the bottom side

    for (int i = SHAPE_ROWS * SHAPE_COLS - 1; i >= 0; i--)
    {
        if (*(shape_grid + i) == 1)
        {
            shapeBottomIndex = i;
            break;
        }
    }

    cout << "\n\n Shape bottom index " << shapeBottomIndex << endl;

    int shapeBottomPixels = 25 * (4 - int(shapeBottomIndex / 5));

    if ((shapeBaseRect.y + 25) <= (groundY + shapeBottomPixels) && !isCollidingDown())
    {
        shapeBaseRect.y += 25;
        return true;
    }
    else
    {
        cout << "updating the grid" << endl;
        updateGrid();
        initShapeGrid();
        // can make different objects here
        return false;
    }
}

void GridLogic::selectShape()
{
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
{
    // writing the shape to grid
    int shapeCoord = 0;
    for (int i = ((shapeBaseRect.y - baseY) / 25); i < ((shapeBaseRect.y - baseY) / 25) + SHAPE_ROWS; i++)
    {
        for (int j = ((shapeBaseRect.x - baseX) / 25); j < ((shapeBaseRect.x - baseX) / 25) + SHAPE_COLS; j++)
        {
            // cout << *(grid + (i * COLS) + j) << " ";
            int gridValue = *(grid + i * COLS + j);

            int shapeValue = *(shape_grid + shapeCoord);
            shapeCoord++;

            if (shapeValue == 1)
                *(grid + i * COLS + j) = 1;
        }
    }

    // checing if any row in the grid is full
    bool flag = false;
    for (int i = 0; i < ROWS; i++)
    {
        flag = true;
        for (int j = 0; j < COLS; j++)
        {
            // cout << *(grid + (i * COLS) + j) << " ";
            int value = *(grid + i * COLS + j);

            if (value == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            removeGridRow(i);
            i--;
        }
    }
}

void GridLogic::removeGridRow(int rowIndex)
{
    for (int i = rowIndex; i >= 0; i--)
    {
        for (int j = 0; j < COLS; j++)
        {
            // cout << *(grid + (i * COLS) + j) << " ";
            int prevJindex = (i - 1) * COLS + j;
            int value;
            if (prevJindex < 0)
                value = 0;
            else
                value = *(grid + (i - 1) * COLS + j);

            *(grid + i * COLS + j) = value;
        }
    }
}

bool GridLogic::isCollidingDown()
{
    int shapeCoord = 0;
    for (int i = ((shapeBaseRect.y - baseY) / 25); i < ((shapeBaseRect.y - baseY) / 25) + SHAPE_ROWS; i++)
    {
        for (int j = ((shapeBaseRect.x - baseX) / 25); j < ((shapeBaseRect.x - baseX) / 25) + SHAPE_COLS; j++)
        {
            int shapeValue = *(shape_grid + shapeCoord);
            shapeCoord++;

            // cout << *(grid + (i * COLS) + j) << " ";
            int gridValue = *(grid + (i + 1) * COLS + j);

            if (shapeValue == 1 && shapeValue == gridValue)
                return true;
        }
    }
    return false;
}

bool GridLogic::isCollidingRight()
{
    int shapeCoord = 0;
    for (int i = ((shapeBaseRect.y - baseY) / 25); i < ((shapeBaseRect.y - baseY) / 25) + SHAPE_ROWS; i++)
    {
        for (int j = ((shapeBaseRect.x - baseX) / 25); j < ((shapeBaseRect.x - baseX) / 25) + SHAPE_COLS; j++)
        {
            int shapeValue = *(shape_grid + shapeCoord);
            shapeCoord++;

            if (shapeValue == 1 && j == COLS - 1) // if the shape is already at the right most corner
                return true;
            // cout << *(grid + (i * COLS) + j) << " ";
            int gridValue = *(grid + i * COLS + (j + 1));

            if (shapeValue == 1 && shapeValue == gridValue)
                return true;
        }
    }
    return false;
}

bool GridLogic::isCollidingLeft()
{
    int shapeCoord = 0;
    for (int i = ((shapeBaseRect.y - baseY) / 25); i < ((shapeBaseRect.y - baseY) / 25) + SHAPE_ROWS; i++)
    {
        for (int j = ((shapeBaseRect.x - baseX) / 25); j < ((shapeBaseRect.x - baseX) / 25) + SHAPE_COLS; j++)
        {
            int shapeValue = *(shape_grid + shapeCoord);
            shapeCoord++;

            if (shapeValue == 1 && j == 0) // if the shape is already at the left most corner
                return true;
            // cout << *(grid + (i * COLS) + j) << " ";
            int gridValue = *(grid + i * COLS + (j - 1));

            if (shapeValue == 1 && shapeValue == gridValue)
                return true;
        }
    }
    return false;
}

void GridLogic::makeShapeI()
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            if (j == 2)
            {
                *(shape_grid + i * SHAPE_COLS + j) = 1;
            }
            else
            {
                *(shape_grid + i * SHAPE_COLS + j) = 0;
            }
        }
    }
}

void GridLogic::makeShapeT()
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            if ((i == 1 && j == 2) || (i == 2 && (j == 1 || j == 2 || j == 3)))
            {
                *(shape_grid + i * SHAPE_COLS + j) = 1;
            }
            else
            {
                *(shape_grid + i * SHAPE_COLS + j) = 0;
            }
        }
    }
}

void GridLogic::makeShapeJ()
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            if ((i == 1 && j == 1) || (i == 2 && (j == 1 || j == 2 || j == 3)))
            {
                *(shape_grid + i * SHAPE_COLS + j) = 1;
            }
            else
            {
                *(shape_grid + i * SHAPE_COLS + j) = 0;
            }
        }
    }
}

void GridLogic::makeShapeL()
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            if ((i == 1 && j == 3) || (i == 2 && (j == 1 || j == 2 || j == 3)))
            {
                *(shape_grid + i * SHAPE_COLS + j) = 1;
            }
            else
            {
                *(shape_grid + i * SHAPE_COLS + j) = 0;
            }
        }
    }
}

void GridLogic::makeShapeO()
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            if ((i == 1 || i == 2) && (j == 1 || j == 2))
            {
                *(shape_grid + i * SHAPE_COLS + j) = 1;
            }
            else
            {
                *(shape_grid + i * SHAPE_COLS + j) = 0;
            }
        }
    }
}

void GridLogic::makeShapeS()
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            if (((i == 1 || i == 2) && j == 2) || (i == 1 && j == 3) || (i == 2 && j == 1))
            {
                *(shape_grid + i * SHAPE_COLS + j) = 1;
            }
            else
            {
                *(shape_grid + i * SHAPE_COLS + j) = 0;
            }
        }
    }
}

void GridLogic::makeShapeZ()
{
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            if (((i == 1 || i == 2) && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 3))
            {
                *(shape_grid + i * SHAPE_COLS + j) = 1;
            }
            else
            {
                *(shape_grid + i * SHAPE_COLS + j) = 0;
            }
        }
    }
}

void GridLogic::rotateShape()
{
    cout << "Rotating the Shape" << endl;
    int *temp = new int[SHAPE_COLS * SHAPE_ROWS];

    for (int blockRowArrow = 0; blockRowArrow < SHAPE_ROWS; blockRowArrow++)
    {
        for (int blockColArrow = 0; blockColArrow < SHAPE_COLS; blockColArrow++)
        {
            temp[(blockColArrow * SHAPE_COLS) + 4 - blockRowArrow] = shape_grid[blockRowArrow * SHAPE_COLS + blockColArrow];
        }
    }

    delete shape_grid;

    shape_grid = temp;
}

void GridLogic::moveShapeLeft()
{
    // here check first if it collides to the left side
    if (!isCollidingLeft())
        shapeBaseRect.x -= 25;
}

void GridLogic::moveShapeRight()
{
    // check first if it collide to the right side
    if (!isCollidingRight())
        shapeBaseRect.x += 25;
}
