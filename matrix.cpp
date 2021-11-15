#include "matrix.h"
#pragma once;
#include <vector>
using namespace std;

__matrix__::__matrix__()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            matrix[i][j] == false;
        }
    }
}

bool __matrix__::get(int row, int col)
{
    return matrix[row][col];
}

void __matrix__::set(int row, int col, bool value)
{
    matrix[row][col] = value;
}