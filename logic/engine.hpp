#pragma once
#include "screen.cpp"
#include "block.cpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

class __engine__ : public __screen__
{
public:
    __screen__ *playground;
    __screen__ *tempPlayground;
    __block__ *tetromino;

    char control();
    void selectPeice();
    void run();
    __engine__();
};