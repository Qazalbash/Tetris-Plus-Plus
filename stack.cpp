#include "stack.h"

__stack__::__stack__()
{
    for (int i = 0; i < ROWS; i++)
    {
        stack[i] = 0;
    }
}

bool __stack__::pop()
{
    int top = stack[-1];
    stack[-1] = 0;
    return top;
}

void __stack__::push(int row, int value)
{
    stack[row] = value;
}