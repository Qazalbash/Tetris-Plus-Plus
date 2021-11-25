#include "../constant.hpp"
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
        for (int screenRowArrow = 0; screenRowArrow < ROWS; screenRowArrow++)
        {
            screen[screenRowArrow] = tempScreen[screenRowArrow];
            // for (int screenColArrow = 0; screenColArrow < 4; screenColArrow++)
            // {
            //     screen[screenRowArrow] = tempScreen[screenRowArrow];
            // }
        }
    }

    void appear()
    {
        cout << "  ";
        for (int screenRowArrow = 0; screenRowArrow < ROWS; screenRowArrow++)
        {
            cout << screenRowArrow % 10 << " ";
        }
        cout << endl;
        for (int screenRowArrow = 0; screenRowArrow < ROWS; screenRowArrow++)
        {
            cout << screenRowArrow << " ";
            screen[screenRowArrow].showStack();
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

    ~__screen__()
    {
        delete screen;
    }
};

int main()
{
    __screen__ *testScreen;
    testScreen->appear();
}
