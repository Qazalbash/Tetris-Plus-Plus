#include "shape.hpp"

shape::shape(int *shape_grid_) : shape_grid(shape_grid_) {}
// {
//     shape_grid = shape_grid_;
// }

void shape::rotateShape()
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
}