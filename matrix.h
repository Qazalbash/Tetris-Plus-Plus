// #include <stdio.h>
#include "constant.h"

class __matrix__
{
    int rows;
    int cols;
    bool matrix[ROWS][COLS];

public:
    void set(int, int, bool);
    bool get(int, int);
    __matrix__ operator+(__matrix__);
    __matrix__();
};
