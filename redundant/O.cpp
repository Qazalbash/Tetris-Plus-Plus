#include "O.hpp"

O::O(int *shape_grid_) : shape::shape(shape_grid_) {}

int *O::makeShape()
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