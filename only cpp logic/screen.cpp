
#include "../constant.hpp"
// #include "movement.cpp"
#include "stack.cpp"
#include <iostream>
using namespace std;

class __screen__ //: public __movement__
{
private:
    __stack__ *screen;

public:
    void update(__screen__ tempScreen)
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                screen[i] = tempScreen[i];
            }
        }
    }

    void appear()
    {
        cout << "  ";
        for (int i = 0; i < ROWS; i++)
        {
            cout << i % 10 << " ";
        }
        cout << endl;
        for (int i = 0; i < COLS; i++)
        {
            cout << i << " ";
            screen[i].showStack();
        }
    }
    __stack__ operator[](const int col)
    {
        return screen[col];
    }

    __screen__()
    {
        screen = new __stack__[COLS];
    }
};