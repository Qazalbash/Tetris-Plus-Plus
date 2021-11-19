// #include "matrix.h"
#pragma once;
#include <iostream>
using namespace std;

class Block
{
    int block[4][4] = {{0, 0, 1, 0},
                       {0, 0, 1, 0},
                       {0, 0, 1, 0},
                       {0, 0, 1, 0}};

public:
    void I();
    // void J();
    // void L();
    // void O();
    // void S();
    // void T();
    // void Z();

    void operator$();

    void show();
    Block();
};