// #include <iostream>
// #include "block.cpp"
// #include "block.hpp"
// using namespace std;

// #include "matrix.h"
// #pragma once;
#include <iostream>
using namespace std;

class Block
{
    int block[4][4] = {{0, 0, 1, 0},
                       {0, 0, 1, 0},
                       {0, 0, 1, 0},
                       {0, 0, 1, 0}};

public:
    void I()
    {
        block[0][2] = 1;
        block[1][2] = 1;
        block[2][2] = 1;
        block[3][2] = 1;
    }
    // void J();
    // void L();
    // void O();
    // void S();
    // void T();
    // void Z();

    void operator$();

    void show()
    {
        cout << block[0][0] << block[0][1] << block[0][2] << block[0][3] << endl;
        cout << block[1][0] << block[1][1] << block[1][2] << block[1][3] << endl;
        cout << block[2][0] << block[2][1] << block[2][2] << block[2][3] << endl;
        cout << block[3][0] << block[3][1] << block[3][2] << block[3][3] << endl;
    }
    // Block();

    void operator$$()
    {
        int temporaryBlock[4][4];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                temporaryBlock[j][3 - i] = block[i][j];
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {

                block[i][j] = temporaryBlock[i][j];
            }
        }
        // block = temporaryBlock;
    }
};

int main()
{
    Block peice;

    // peice.show();
    peice.I();
    peice.show();
    peice;
    peice.show();
    return 0;
}