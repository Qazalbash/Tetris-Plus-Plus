#include "../constant.hpp"
#include <iostream>
using namespace std;

class __stack__
{
private:
    int *stack;

protected:
    int top;

public:
    void pop()
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

    void push(int row, int value)
    {
        stack[row] = value;
        top = row;
    }

    void showStack()
    {
        for (int stackArrow = 0; stackArrow < ROWS; stackArrow++)
        {
            cout << *(stack + stackArrow) << " ";
        }
        cout << endl;
    }

    int operator[](int row)
    {
        return stack[row];
    }

    void operator=(__stack__ tempStack)
    {
        for (int stackArrow = 0; stackArrow < ROWS; stackArrow++)
        {
            stack[stackArrow] = tempStack[stackArrow];
        }
    }

    __stack__()
    {
        stack = new int[COLS];
        for (int stackArrow = 0; stackArrow < ROWS; stackArrow++)
        {
            stack[stackArrow] = 0;
        }
        top = -1;
    }

    ~__stack__()
    {
        delete stack;
    }
};