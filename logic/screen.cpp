#include "screen.hpp "

void __screen__::update()
{
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
    cout << "------------Game Start------------" << endl;
}