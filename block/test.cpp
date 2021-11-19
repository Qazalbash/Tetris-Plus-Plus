// #include "block.hpp"
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
class __block__
{
    int **blk;

public:
    void I()
    {
        // cout << "I am in I" << endl;
        blk[0][2] = 1;
        blk[1][2] = 1;
        blk[2][2] = 1;
        blk[3][2] = 1;
    }
    void J();
    void L();
    void O();
    void S();
    void T();
    void Z();

    void operator$();

    void show()
    {
        cout << blk[0][0] << blk[0][1] << blk[0][2] << blk[0][3] << endl;
        cout << blk[1][0] << blk[1][1] << blk[1][2] << blk[1][3] << endl;
        cout << blk[2][0] << blk[2][1] << blk[2][2] << blk[2][3] << endl;
        cout << blk[3][0] << blk[3][1] << blk[3][2] << blk[3][3] << endl;
    }

    __block__(int **);
    __block__()
    {
        blk = new int *[4];
        blk[0] = new int[4];
        blk[1] = new int[4];
        blk[2] = new int[4];
        blk[3] = new int[4];

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                blk[i][j] = 1;
            }
        }
    }
};

int main()
{
    __block__ *peice;

    peice->I();
    peice->show();
    // peice->show();
    // std::cout << peice->blk[0][0] << peice->blk[0][1] << peice->blk[0][2] << peice->blk[0][3] << std::endl;
    // std::cout << peice->blk[1][0] << peice->blk[1][1] << peice->blk[1][2] << peice->blk[1][3] << std::endl;
    // std::cout << peice->blk[2][0] << peice->blk[2][1] << peice->blk[2][2] << peice->blk[2][3] << std::endl;
    // std::cout << peice->blk[3][0] << peice->blk[3][1] << peice->blk[3][2] << peice->blk[3][3] << std::endl;
    return 0;
}