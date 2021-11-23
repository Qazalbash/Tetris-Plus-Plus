#include "screen.hpp"

void __screen__::update(__screen__ tempScreen)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            screen[i] = tempScreen[i];
        }
    }
}

void __screen__::appear()
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

__screen__::__screen__()
{
    screen = new __stack__[COLS];
}

__stack__ __screen__::operator[](const int col)
{
    return screen[col];
}