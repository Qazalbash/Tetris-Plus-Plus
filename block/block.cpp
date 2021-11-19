#include "block.hpp"

__block__::__block__()
{
    block = new int *[4];
    block[0] = new int[4];
    block[1] = new int[4];
    block[2] = new int[4];
    block[3] = new int[4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            block[i][j] = 0;
        }
    }
}

void __block__::I()
{
    block[0][2] = 1;
    block[1][2] = 1;
    block[2][2] = 1;
    block[3][2] = 1;
}

void __block__::J()
{
    block[1][1] = 1;
    block[2][1] = 1;
    block[2][2] = 1;
    block[2][3] = 1;
}

void __block__::L()
{
    block[1][3] = 1;
    block[2][1] = 1;
    block[2][2] = 1;
    block[2][3] = 1;
}

void __block__::O()
{
    block[1][1] = 1;
    block[1][2] = 1;
    block[2][1] = 1;
    block[2][2] = 1;
}

void __block__::S()
{
    block[1][2] = 1;
    block[1][3] = 1;
    block[2][1] = 1;
    block[2][2] = 1;
}

void __block__::T()
{
    block[1][1] = 1;
    block[2][0] = 1;
    block[2][1] = 1;
    block[2][2] = 1;
}

void __block__::Z()
{
    block[1][1] = 1;
    block[1][2] = 1;
    block[2][2] = 1;
    block[2][3] = 1;
}

void __block__::operator$()
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
}

void __block__::show()
{
    cout << block[0][0] << block[0][1] << block[0][2] << block[0][3] << endl;
    cout << block[1][0] << block[1][1] << block[1][2] << block[1][3] << endl;
    cout << block[2][0] << block[2][1] << block[2][2] << block[2][3] << endl;
    cout << block[3][0] << block[3][1] << block[3][2] << block[3][3] << endl;
}