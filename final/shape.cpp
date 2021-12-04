#include "shape.hpp"

shape::shape(int R, int C) : SHAPE_ROWS(R), SHAPE_COLS(C)
{
    shape_grid = new int[25];
    for (int i = 0; i < SHAPE_ROWS; i++)
    {
        for (int j = 0; j < SHAPE_COLS; j++)
        {
            *(shape_grid + i * SHAPE_COLS + j) = 0;
        }
    }
}

// shape::~shape()
// {
//     delete shape_grid;
// }

int *shape::rotateShape()
{
    cout << "Rotating the Shape" << endl;
    int *temp = new int[SHAPE_COLS * SHAPE_ROWS];

    for (int blockRowArrow = 0; blockRowArrow < SHAPE_ROWS; blockRowArrow++)
    {
        for (int blockColArrow = 0; blockColArrow < SHAPE_COLS; blockColArrow++)
        {
            temp[blockColArrow * SHAPE_COLS + 4 - blockRowArrow] = shape_grid[blockRowArrow * SHAPE_COLS + blockColArrow];
        }
    }

    delete shape_grid;

    shape_grid = temp;

    return shape_grid;
}

int *shape::makeShapeI()
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
    return shape_grid;
}
int *shape::makeShapeT()
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
    return shape_grid;
}

int *shape::makeShapeJ()
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
    return shape_grid;
}

int *shape::makeShapeL()
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
    return shape_grid;
}
int *shape::makeShapeO()
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
    return shape_grid;
}

int *shape::makeShapeS()
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
    return shape_grid;
}
int *shape::makeShapeZ()
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
    return shape_grid;
}