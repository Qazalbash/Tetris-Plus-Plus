#include "Z.hpp"

Z::Z(int *shape_grid_) : shape::shape(shape_grid_) {}

void Z::makeShape()
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