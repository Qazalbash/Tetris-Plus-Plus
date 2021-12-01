#include <iostream>
using namespace std;

class __block__
{
public:
    int row;
    int column;
    int rightWallColumnNumber;
    int leftWallColumnNumber;
    int upperWallRowNumber;
    int bottomWallRowNumber;

    void I()
    {
        nullBlock();

        blk[0][2] = 1;
        blk[1][2] = 1;
        blk[2][2] = 1;
        blk[3][2] = 1;

        updateWallIndexes();
    }

    void J()
    {
        nullBlock();

        blk[1][1] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;

        updateWallIndexes();
    }

    void L()
    {
        nullBlock();

        blk[1][3] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;

        updateWallIndexes();
    }

    void O()
    {
        nullBlock();

        blk[1][1] = 1;
        blk[1][2] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;

        updateWallIndexes();
    }

    void S()
    {
        nullBlock();

        blk[1][2] = 1;
        blk[1][3] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;

        updateWallIndexes();
    }

    void T()
    {
        nullBlock();

        blk[1][2] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;

        updateWallIndexes();
    }

    void Z()
    {
        nullBlock();

        blk[1][1] = 1;
        blk[1][2] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;

        updateWallIndexes();
    }

    void operator~()
    {
        static int temporaryBlock[5][5];
        for (int blockRowArrow = 0; blockRowArrow < 5; blockRowArrow++)
        {
            for (int blockColArrow = 0; blockColArrow < 5; blockColArrow++)
            {
                temporaryBlock[blockColArrow][4 - blockRowArrow] = blk[blockRowArrow][blockColArrow];
            }
        }

        for (int blockRowArrow = 0; blockRowArrow < 5; blockRowArrow++)
        {
            for (int blockColArrow = 0; blockColArrow < 5; blockColArrow++)
            {
                blk[blockRowArrow][blockColArrow] = temporaryBlock[blockRowArrow][blockColArrow];
            }
        }

        updateWallIndexes();
    }

    void show()
    {
        cout << blk[0][0] << " " << blk[0][1] << " " << blk[0][2] << " " << blk[0][3] << " " << blk[0][4] << endl;
        cout << blk[1][0] << " " << blk[1][1] << " " << blk[1][2] << " " << blk[1][3] << " " << blk[1][4] << endl;
        cout << blk[2][0] << " " << blk[2][1] << " " << blk[2][2] << " " << blk[2][3] << " " << blk[2][4] << endl;
        cout << blk[3][0] << " " << blk[3][1] << " " << blk[3][2] << " " << blk[3][3] << " " << blk[3][4] << endl;
        cout << blk[4][0] << " " << blk[4][1] << " " << blk[4][2] << " " << blk[4][3] << " " << blk[4][4] << endl;
    }

    int *operator[](int x)
    {
        return blk[x];
    }

    __block__()
    {
        blk = new int *[5];
        blk[0] = new int[5];
        blk[1] = new int[5];
        blk[2] = new int[5];
        blk[3] = new int[5];
        blk[4] = new int[5];

        nullBlock();

        row = 0;
        column = 2;
    }

    ~__block__()
    {
        delete[] blk;
    }

protected:
    int **blk;

    void nullBlock()
    {
        for (int blockRowArrow = 0; blockRowArrow < 5; blockRowArrow++)
        {
            for (int blockColArrow = 0; blockColArrow < 5; blockColArrow++)
            {
                blk[blockRowArrow][blockColArrow] = 0;
            }
        }
    }

    int updateUpperWallRowNumber()
    {
        for (int blockRowArrow = 0; blockRowArrow < 5; blockRowArrow++)
        {
            for (int blockColArrow = 0; blockColArrow < 5; blockColArrow++)
            {
                if (blk[blockRowArrow][blockColArrow] == 1)
                {
                    return blockRowArrow;
                }
            }
        }
        return bottomWallRowNumber;
    }

    int updateBottomWallRowNumber()
    {
        for (int blockRowArrow = 4; blockRowArrow > -1; blockRowArrow--)
        {
            for (int blockColArrow = 0; blockColArrow < 5; blockColArrow++)
            {
                if (blk[blockRowArrow][blockColArrow] == 1)
                {
                    return blockRowArrow;
                }
            }
        }
        return bottomWallRowNumber;
    }

    int updateRightWallColumnNumber()
    {
        for (int blockColArrow = 4; blockColArrow > -1; blockColArrow--)
        {
            for (int blockRowArrow = 0; blockRowArrow < 4; blockRowArrow++)
            {
                if (blk[blockRowArrow][blockColArrow] == 1)
                {
                    return blockColArrow;
                }
            }
        }
        return rightWallColumnNumber;
    }

    int updateLeftWallColumnNumber()
    {
        for (int blockColArrow = 0; blockColArrow < 5; blockColArrow++)
        {
            for (int blockRowArrow = 0; blockRowArrow < 4; blockRowArrow++)
            {
                if (blk[blockRowArrow][blockColArrow] == 1)
                {
                    return blockColArrow;
                }
            }
        }
        return leftWallColumnNumber;
    }

    void updateWallIndexes()
    {

        rightWallColumnNumber = updateRightWallColumnNumber();
        leftWallColumnNumber = updateLeftWallColumnNumber();
        upperWallRowNumber = updateUpperWallRowNumber();
        bottomWallRowNumber = updateBottomWallRowNumber();
    }
};