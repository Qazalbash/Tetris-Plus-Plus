#pragma once;
#include "matrix.hpp"
using namespace std;

__matrix__::__matrix__()
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
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

__matrix__ __matrix__::operator+(__matrix__ A)
{
    __matrix__ C;
    bool c;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            c = matrix[i][j] + A.get(i, j);
            C.set(i, j, c);
        }
    }
    return C;
}
