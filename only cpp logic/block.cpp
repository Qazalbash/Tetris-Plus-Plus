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
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                temporaryBlock[j][3 - i] = blk[i][j];
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                blk[i][j] = temporaryBlock[i][j];
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

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                blk[i][j] = 0;
            }
        }

        x = 3;
        y = 19;
    }
};

// int main()
// {
//     __block__ peice;
//     peice.I();
//     peice.show();

//     return 0;
// }