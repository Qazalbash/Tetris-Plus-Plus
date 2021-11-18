#include "block.hpp"

Block::Block() {}

void Block::I()
{
    blk = {{0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 0, 1, 0}};
}

void Block::J()
{
    blk = {{0, 0, 0, 0},
           {0, 1, 0, 0},
           {0, 1, 1, 1},
           {0, 0, 0, 0}};
}

void Block::L()
{
    blk = {{0, 0, 0, 0},
           {0, 0, 0, 1},
           {0, 1, 1, 1},
           {0, 0, 0, 0}};
}

void Block::O()
{
    blk = {{0, 0, 0, 0},
           {0, 1, 1, 0},
           {0, 1, 1, 0},
           {0, 0, 0, 0}};
}

void Block::S()
{
    Block::blk = {{0, 0, 0, 0},
                  {0, 0, 1, 1},
                  {0, 1, 1, 0},
                  {0, 0, 0, 0}};
}

void Block::T()
{
    blk = {{0, 0, 0, 0},
           {0, 1, 0, 0},
           {1, 1, 1, 0},
           {0, 0, 0, 0}};
}

void Block::Z()
{
    blk = {{0, 0, 0, 0},
           {0, 1, 1, 0},
           {0, 0, 1, 1},
           {0, 0, 0, 0}};
}

void Block::operator$()
{
    int temporaryBlock[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temporaryBlock[j][3 - i] = blk[i][j];
        }
    }
    blk = temporaryBlock;
}

void Block::show()
{
    cout << blk[0][0] << blk[0][1] << blk[0][2] << blk[0][3] << endl;
    cout << blk[1][0] << blk[1][1] << blk[1][2] << blk[1][3] << endl;
    cout << blk[2][0] << blk[2][1] << blk[2][2] << blk[2][3] << endl;
    cout << blk[3][0] << blk[3][1] << blk[3][2] << blk[3][3] << endl;
}