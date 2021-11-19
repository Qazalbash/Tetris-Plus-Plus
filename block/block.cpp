#include "block.hpp"

Block::Block()
{
    block[4][4] = {{0, 0, 1, 0},
                   {0, 0, 1, 0},
                   {0, 0, 1, 0},
                   {0, 0, 1, 0}};
}
// {
//     block =
// }

void Block::I()
{
    // block[0][2] = 1;
    // block[1][2] = 1;
    // block[2][2] = 1;
    // block[3][2] = 1;
    block[4][4] = {{0, 0, 1, 0},
                   {0, 0, 1, 0},
                   {0, 0, 1, 0},
                   {0, 0, 1, 0}};
}

// void Block::J()
// {
//     block = {{0, 0, 0, 0},
//            {0, 1, 0, 0},
//            {0, 1, 1, 1},
//            {0, 0, 0, 0}};
// }

// void Block::L()
// {
//     block = {{0, 0, 0, 0},
//            {0, 0, 0, 1},
//            {0, 1, 1, 1},
//            {0, 0, 0, 0}};
// }

// void Block::O()
// {
//     block = {{0, 0, 0, 0},
//            {0, 1, 1, 0},
//            {0, 1, 1, 0},
//            {0, 0, 0, 0}};
// }

// void Block::S()
// {
//     Block::block = {{0, 0, 0, 0},
//                   {0, 0, 1, 1},
//                   {0, 1, 1, 0},
//                   {0, 0, 0, 0}};
// }

// void Block::T()
// {
//     block = {{0, 0, 0, 0},
//            {0, 1, 0, 0},
//            {1, 1, 1, 0},
//            {0, 0, 0, 0}};
// }

// void Block::Z()
// {
//     block = {{0, 0, 0, 0},
//            {0, 1, 1, 0},
//            {0, 0, 1, 1},
//            {0, 0, 0, 0}};
// }

void Block::operator$()
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

void Block::show()
{
    cout << block[0][0] << block[0][1] << block[0][2] << block[0][3] << endl;
    cout << block[1][0] << block[1][1] << block[1][2] << block[1][3] << endl;
    cout << block[2][0] << block[2][1] << block[2][2] << block[2][3] << endl;
    cout << block[3][0] << block[3][1] << block[3][2] << block[3][3] << endl;
}