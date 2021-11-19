#include <stdio.h>
#include "constant.hpp"

class __stack__
{
private:
    int stack[ROWS];

public:
    bool pop();
    void push(int, int);
    __stack__();
};