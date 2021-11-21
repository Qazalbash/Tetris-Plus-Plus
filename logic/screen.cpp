#include "screen.hpp"

void __screen__::update(__screen__ **tempScreen)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            screen[i][j] = tempScreen[i][j];
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
        screen[i]->showStack();
    }
}
__screen__::__screen__()
{
    cout << "------------Game Start------------" << endl;
    screen = new __stack__ *[COLS];
}