#include <stdio.h>
#include <constant.h>

class __stack__
{
private:
    int stack[ROWS];

public:
    bool pop();
    void push(int, int);
    __stack__();
};