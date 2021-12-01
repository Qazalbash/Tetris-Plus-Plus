#include "constant.hpp"
#include <iostream>
using namespace std;

class __screen__
{

private:
    int **screen;

public:
    void update(__screen__ tempScreen)
    {
        for (int tempScreenRowArrow = 0; tempScreenRowArrow < ROWS; tempScreenRowArrow++)
        {
            screen[tempScreenRowArrow] = tempScreen[tempScreenRowArrow];
        }
    }

    void appear()
    {
        for (int screenRowArrow = 0; screenRowArrow < ROWS; screenRowArrow++)
        {
            for (int screenColArrow = 0; screenColArrow < COLS; screenColArrow++)
            {
                cout << screen[screenRowArrow][screenColArrow] << " ";
            }
            cout << endl;
        }
    }

    int *operator[](const int col)
    {
        return screen[col];
    }

    __screen__()
    {
        screen = new int *[ROWS];
        for (int screenArrow = 0; screenArrow < ROWS; screenArrow++)
        {
            screen[screenArrow] = new int[COLS];
        }

        for (int screenRowArrow = 0; screenRowArrow < ROWS; screenRowArrow++)
        {
            for (int screenColArrow = 0; screenColArrow < COLS; screenColArrow++)
            {
                screen[screenRowArrow][screenColArrow] = 0;
            }
        }
    }
};