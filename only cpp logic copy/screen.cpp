#include "constant.hpp"
#include <iostream>
#include <stack>
using namespace std;

class __screen__
{

private:
    int **screen;

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
            cout << screen[i][j] << endl;
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
    }
    // __screen__(int a)
    // {
    //     cout << " int " << a << endl;
    // }
};

int main()
{
    cout << "start" << endl;
    __screen__ testScreen;

    cout << "end" << endl;
    return 0;
}