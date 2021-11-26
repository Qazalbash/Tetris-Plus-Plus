#include <iostream>
using namespace std;

class __block__
{
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

public:
    int x;
    int y;
    void I()
    {
        nullBlock();

        blk[0][2] = 1;
        blk[1][2] = 1;
        blk[2][2] = 1;
        blk[3][2] = 1;
    }

    void J()
    {
        nullBlock();

        blk[1][1] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;
    }

    void L()
    {
        nullBlock();

        blk[1][3] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;
    }

    void O()
    {
        nullBlock();

        blk[1][1] = 1;
        blk[1][2] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
    }

    void S()
    {
        nullBlock();

        blk[1][2] = 1;
        blk[1][3] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
    }

    void T()
    {
        nullBlock();

        blk[1][2] = 1;
        blk[2][1] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;
    }

    void Z()
    {
        nullBlock();

        blk[1][1] = 1;
        blk[1][2] = 1;
        blk[2][2] = 1;
        blk[2][3] = 1;
    }

    void operator~()
    {
        int temporaryBlock[5][5];
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
        // blk = new int *[5];
        // blk[0] = new int[5];
        // blk[1] = new int[5];
        // blk[2] = new int[5];
        // blk[3] = new int[5];
        // blk[4] = new int[5];

        nullBlock();

        x = 0;
        y = 2;
    }
};

struct topLeft
{
    int x;
    int y;

    topLeft(int xx, int yy) : x(xx), y(yy) {}
};

class I : public __block__
{
private:
    int x;
    int y;
    int xlength;
    int ylength;

public:
    void rotate() {}
    I()
    {
        blk = new int *[4];
        blk[0] = new int[1];
        blk[1] = new int[1];
        blk[2] = new int[1];
        blk[3] = new int[1];

        blk[0][0] = 1;
        blk[1][0] = 1;
        blk[2][0] = 1;
        blk[3][0] = 1;

        xlength = 1;
        ylength = 4;
    }
    ~I()
    {
        delete[] blk;
    }
};

class J : public __block__
{
private:
    int x;
    int y;
    int xlength;
    int ylength;

public:
    void rotate() {}

    J()
    {
        blk = new int *[3];
        blk[0] = new int[2];
        blk[1] = new int[2];
        blk[2] = new int[2];

        blk[0][0] = 0;
        blk[0][1] = 1;
        blk[1][0] = 0;
        blk[1][1] = 1;
        blk[2][0] = 1;
        blk[2][1] = 1;

        xlength = 2;
        ylength = 3;
    }

    ~J()
    {
        delete[] blk;
    }
};
class L : public __block__
{
private:
    int x;
    int y;
    int xlength;
    int ylength;

public:
    void rotate() {}
    L() {}
    ~L()
    {
        delete[] blk;
    }
};
class O : public __block__
{
private:
    int x;
    int y;
    int xlength;
    int ylength;

public:
    void rotate() {}
    O() {}
    ~O()
    {
        delete[] blk;
    }
};
class S : public __block__
{
private:
    int x;
    int y;
    int xlength;
    int ylength;

public:
    void rotate() {}
    S() {}
    ~S()
    {
        delete[] blk;
    }
};
class T : public __block__
{
private:
    int x;
    int y;
    int xlength;
    int ylength;

public:
    void rotate() {}
    T() {}
    ~T()
    {
        delete[] blk;
    }
};
class Z : public __block__
{
private:
    int x;
    int y;
    int xlength;
    int ylength;

public:
    void rotate() {}
    Z() {}
    ~Z()
    {
        delete[] blk;
    }
};