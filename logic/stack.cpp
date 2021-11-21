#include "stack.hpp"

__stack__::__stack__()
{
    stack = new int[COLS];
    for (int i = 0; i < ROWS; i++)
    {
        stack[i] = 0;
    }
    top = -1;
}

void __stack__::pop()
{
    if (stack[top] == 1 && top != -1)
    {
        stack[top] = 0;
        for (int i = 0; i < 10; i++)
        {
            if (stack[i] == 1)
            {
                top = i;
                break;
            }
        }
    }
}

void __stack__::push(int row, int value)
{
    stack[row] = value;
    top = row;
}

void __stack__::showStack()
{
    for (int i = 0; i < ROWS; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int __stack__::operator[](int row)
{
    return stack[row];
}

void __stack__::operator=(__stack__ tempStack)
{
    for (int i = 0; i < ROWS; i++)
    {
        stack[i] = tempStack[i];
    }
}