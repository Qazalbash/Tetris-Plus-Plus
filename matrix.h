#include <stdio.h>
#include "constant.h"

class __matrix__
{
    bool matrix[ROWS][COLS];

public:
    void set(int row, int col, bool value);
    bool get(int row, int col);
    __matrix__();
};