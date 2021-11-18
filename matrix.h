#include <stdio.h>

#define ROWS 15
#define COLS 15

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
