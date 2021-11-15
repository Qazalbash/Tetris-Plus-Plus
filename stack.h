#include <stdio.h>
#include "constant.h"

class __stack__
{
private:
    bool stack[ROWS];

public:
    bool pop();
    void push();
    __stack__();
};