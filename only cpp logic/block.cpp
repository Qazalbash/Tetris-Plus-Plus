#include <iostream>
using namespace std;

class __block__
{
private:
    int **blk;

public:
    int x;
    int y;

    void I()
    {
        blk[0][2] = 1;
        blk[1][2] = 1;
        blk[2][2] = 1;
        blk[3][2] = 1;
    }

    void J()
    {
        blk[1][1] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;
    }

    void L()
    {
        blk[1][3] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;
    }

    void O()
    {
        blk[1][1] = 1;
        blk[1][2] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
    }

    void S()
    {
        blk[1][2] = 1;
        blk[1][3] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
    }

    void T()
    {
        blk[1][1] = 1;
        blk[2][0] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
    }

    void Z()
    {
        blk[1][1] = 1;
        blk[1][2] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;
    }

    void operator~()
    {
        int temporaryBlock[4][4];
        for (int blockRowArrow = 0; blockRowArrow < 4; blockRowArrow++)
        {
            for (int blockColArrow = 0; blockColArrow < 4; blockColArrow++)
            {
                temporaryBlock[blockColArrow][3 - blockRowArrow] = blk[blockRowArrow][blockColArrow];
            }
        }

        for (int blockRowArrow = 0; blockRowArrow < 4; blockRowArrow++)
        {
            for (int blockColArrow = 0; blockColArrow < 4; blockColArrow++)
            {
                blk[blockRowArrow][blockColArrow] = temporaryBlock[blockRowArrow][blockColArrow];
            }
        }
    }

    void show()
    {
        cout << blk[0][0] << " " << blk[0][1] << " " << blk[0][2] << " " << blk[0][3] << endl;
        cout << blk[1][0] << " " << blk[1][1] << " " << blk[1][2] << " " << blk[1][3] << endl;
        cout << blk[2][0] << " " << blk[2][1] << " " << blk[2][2] << " " << blk[2][3] << endl;
        cout << blk[3][0] << " " << blk[3][1] << " " << blk[3][2] << " " << blk[3][3] << endl;
    }

    __block__()
    {
        blk = new int *[4];
        blk[0] = new int[4];
        blk[1] = new int[4];
        blk[2] = new int[4];
        blk[3] = new int[4];

        for (int blockRowArrow = 0; blockRowArrow < 4; blockRowArrow++)
        {
            for (int blockColArrow = 0; blockColArrow < 4; blockColArrow++)
            {
                blk[blockRowArrow][blockColArrow] = 0;
            }
        }

        x = 3;
        y = 19;
    }

    ~__block__()
    {
        delete blk[0];
        delete blk[1];
        delete blk[2];
        delete blk[3];
        delete blk;
    }
};

// int main()
// {
//     __block__ peice;
//     peice.J();
//     peice.show();

//     return 0;
// }