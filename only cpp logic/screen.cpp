#include "../constant.hpp"
// #include "stack.cpp"
#include <iostream>
#include <stack>
using namespace std;

class __screen__ //: public __movement__
{
private:
    stack < *screen;

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
            //screen[i].showStack();
            //cout << (screen[i]) << endl;
        }
    }
    stack<int> operator[](const int col)
    {
        return screen[col];
    }

    __screen__(int size)
    {
        cout << "inside the consturc" << endl;
        stack<int> screen;
    }
    // __screen__(int a)
    // {
    //     cout << " int " << a << endl;
    // }
};

int main()
{
    cout << "start" << endl;
    __screen__ testScreen(COLS);

    //testScreen.appear();

    cout << "end" << endl;
    return 0;
}