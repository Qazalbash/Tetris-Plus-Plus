#include "stack.hpp"

__stack__::__stack__()
{
    for (int i = 0; i < ROWS; i++)
    {
        stack[i] = 0;
    }
}

int __stack__::pop()
{
    int top = stack[-1];
    stack[-1] = 0;
    return top;
}

void __stack__::push(int row, int value)
{
    stack[row] = value;
}