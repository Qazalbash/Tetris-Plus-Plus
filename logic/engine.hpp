#pragma once
#include "screen.cpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

class __engine__ : public __screen__
{
    __screen__ *playground;
    __screen__ *tempPlayground;
    __block__ *tetromino;

public:
    char control();
    void selectPeice();
    void run();
    __engine__();
};