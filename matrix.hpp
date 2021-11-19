// #include <stdio.h>
#include "constant.hpp"

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
