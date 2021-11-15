#include "stack.h"

__stack__::__stack__()
{
    for (int i = 0; i < ROWS; i++)
    {
        stack[i] = false;
    }
}

bool __stack__::pop()
{
    bool top = stack[-1];
    stack[-1] = false;
    return top;
}

void __stack__::push()
{
}