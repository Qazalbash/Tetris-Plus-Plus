#include <iostream>
using namespace std;

class __block__
{
protected:
    int **blk;

    int xlength;
    int ylength;

    int rotationNumber = 0;

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
        nullBlock();

        x = 0;
        y = 2;
    }
};

class I : public __block__
{
private:
public:
    void definition0()
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

    void definition1()
    {
        blk = new int *[1];
        blk[0] = new int[4];

        blk[0][0] = 1;
        blk[0][1] = 1;
        blk[0][2] = 1;
        blk[0][3] = 1;

        xlength = 4;
        ylength = 1;
    }

    void rotate()
    {
        if (rotationNumber == 1)
        {
            delete[] blk;
            definition0();
            rotationNumber = 1;
        }

        else
        {
            delete[] blk;
            definition1();
            rotationNumber = 0;
        }
    }

    I() { definition0(); }

    ~I() { delete[] blk; }
};

class J : public __block__
{

public:
    void definition0()
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

    void definition1()
    {
        blk = new int *[2];
        blk[0] = new int[3];
        blk[1] = new int[3];

        blk[0][0] = 1;
        blk[0][1] = 0;
        blk[0][2] = 0;
        blk[1][0] = 1;
        blk[1][1] = 1;
        blk[1][2] = 1;

        xlength = 3;
        ylength = 2;
    }

    void definition2()
    {
        blk = new int *[3];
        blk[0] = new int[2];
        blk[1] = new int[2];
        blk[2] = new int[2];

        blk[0][0] = 1;
        blk[0][1] = 1;
        blk[1][0] = 1;
        blk[1][1] = 0;
        blk[2][0] = 1;
        blk[2][1] = 0;

        xlength = 2;
        ylength = 3;
    }

    void definition3()
    {
        blk = new int *[2];
        blk[0] = new int[3];
        blk[1] = new int[3];

        blk[0][0] = 1;
        blk[0][1] = 1;
        blk[0][2] = 1;
        blk[1][0] = 0;
        blk[1][1] = 0;
        blk[1][2] = 1;

        xlength = 3;
        ylength = 2;
    }

    void rotate()
    {
        switch (rotationNumber)
        {
        case 0:
            definition1();
            rotationNumber = 1;
            break;

        case 1:
            definition2();
            rotationNumber = 2;
            break;

        case 2:
            definition3();
            rotationNumber = 3;
            break;

        case 3:
            definition0();
            rotationNumber = 0;
            break;
        }
    }

    J() { definition0(); }

    ~J() { delete[] blk; }
};

class L : public __block__
{

public:
    void definition0()
    {
        blk = new int *[3];
        blk[0] = new int[2];
        blk[1] = new int[2];
        blk[2] = new int[2];

        blk[0][0] = 1;
        blk[0][1] = 0;
        blk[1][0] = 1;
        blk[1][1] = 0;
        blk[2][0] = 1;
        blk[2][1] = 1;

        xlength = 2;
        ylength = 3;
    }

    void definition1()
    {
        blk = new int *[2];
        blk[0] = new int[3];
        blk[1] = new int[3];

        blk[0][0] = 1;
        blk[0][1] = 0;
        blk[0][2] = 0;
        blk[1][0] = 1;
        blk[1][1] = 1;
        blk[1][2] = 1;

        xlength = 3;
        ylength = 2;
    }

    void definition2()
    {
        blk = new int *[3];
        blk[0] = new int[2];
        blk[1] = new int[2];
        blk[2] = new int[2];

        blk[0][0] = 1;
        blk[0][1] = 1;
        blk[1][0] = 0;
        blk[1][1] = 1;
        blk[2][0] = 0;
        blk[2][1] = 1;

        xlength = 2;
        ylength = 3;
    }

    void definition3()
    {
        blk = new int *[2];
        blk[0] = new int[3];
        blk[1] = new int[3];

        blk[0][0] = 0;
        blk[0][1] = 0;
        blk[0][2] = 1;
        blk[1][0] = 1;
        blk[1][1] = 1;
        blk[1][2] = 1;

        xlength = 3;
        ylength = 2;
    }

    void rotate()
    {
        switch (rotationNumber)
        {
        case 0:
            definition1();
            rotationNumber = 1;
            break;

        case 1:
            definition2();
            rotationNumber = 2;
            break;

        case 2:
            definition3();
            rotationNumber = 3;
            break;

        case 3:
            definition0();
            rotationNumber = 0;
            break;
        }
    }

    L() { definition0(); }

    ~L() { delete[] blk; }
};

class O : public __block__
{

public:
    void rotate() {}

    O()
    {
        blk = new int *[2];
        blk[0] = new int[2];
        blk[1] = new int[2];

        blk[0][0] = 1;
        blk[0][1] = 1;
        blk[1][0] = 1;
        blk[1][1] = 1;

        xlength = 2;
        ylength = 2;
    }

    ~O() { delete[] blk; }
};

class S : public __block__
{

public:
    void definition0()
    {
        blk = new int *[2];
        blk[0] = new int[3];
        blk[1] = new int[3];

        blk[0][0] = 0;
        blk[0][1] = 1;
        blk[0][2] = 1;
        blk[1][0] = 1;
        blk[1][1] = 1;
        blk[1][2] = 0;

        xlength = 3;
        ylength = 2;
    }

    void definition1()
    {
        blk = new int *[3];
        blk[0] = new int[2];
        blk[1] = new int[2];
        blk[2] = new int[2];

        blk[0][0] = 1;
        blk[0][1] = 0;
        blk[1][0] = 1;
        blk[1][1] = 1;
        blk[2][0] = 0;
        blk[2][1] = 1;

        xlength = 2;
        ylength = 3;
    }

    void rotate()
    {
        if (rotationNumber == 1)
        {
            delete[] blk;
            definition0();
            rotationNumber = 1;
        }

        else
        {
            delete[] blk;
            definition1();
            rotationNumber = 0;
        }
    }

    S() { definition0(); }

    ~S() { delete[] blk; }
};

class T : public __block__
{

public:
    void definition0()
    {
        blk = new int *[2];
        blk[0] = new int[3];
        blk[1] = new int[3];

        blk[0][0] = 0;
        blk[0][1] = 1;
        blk[0][2] = 0;
        blk[1][0] = 1;
        blk[1][1] = 1;
        blk[1][2] = 1;

        xlength = 3;
        ylength = 2;
    }

    void definition1()
    {
        blk = new int *[3];
        blk[0] = new int[2];
        blk[1] = new int[2];
        blk[2] = new int[2];

        blk[0][0] = 1;
        blk[0][1] = 0;
        blk[1][0] = 1;
        blk[1][1] = 1;
        blk[2][0] = 1;
        blk[2][1] = 0;

        xlength = 2;
        ylength = 3;
    }

    void definition2()
    {
        blk = new int *[2];
        blk[0] = new int[3];
        blk[1] = new int[3];

        blk[0][0] = 1;
        blk[0][1] = 1;
        blk[0][2] = 1;
        blk[1][0] = 0;
        blk[1][1] = 1;
        blk[1][2] = 0;

        xlength = 3;
        ylength = 2;
    }

    void definition3()
    {
        blk = new int *[3];
        blk[0] = new int[2];
        blk[1] = new int[2];
        blk[2] = new int[2];

        blk[0][0] = 0;
        blk[0][1] = 1;
        blk[1][0] = 1;
        blk[1][1] = 1;
        blk[2][0] = 0;
        blk[2][1] = 1;

        xlength = 2;
        ylength = 3;
    }

    void rotate()
    {
        switch (rotationNumber)
        {
        case 0:
            definition1();
            rotationNumber = 1;
            break;

        case 1:
            definition2();
            rotationNumber = 2;
            break;

        case 2:
            definition3();
            rotationNumber = 3;
            break;

        case 3:
            definition0();
            rotationNumber = 0;
            break;
        }
    }

    T() { definition0(); }

    ~T() { delete[] blk; }
};

class Z : public __block__
{

public:
    void definition0()
    {
        blk = new int *[2];
        blk[0] = new int[3];
        blk[1] = new int[3];

        blk[0][0] = 1;
        blk[0][1] = 1;
        blk[0][2] = 0;
        blk[1][0] = 0;
        blk[1][1] = 1;
        blk[1][2] = 1;

        xlength = 3;
        ylength = 2;
    }

    void definition1()
    {
        blk = new int *[3];
        blk[0] = new int[2];
        blk[1] = new int[2];
        blk[2] = new int[2];

        blk[0][0] = 0;
        blk[0][1] = 1;
        blk[1][0] = 1;
        blk[1][1] = 1;
        blk[2][0] = 1;
        blk[2][1] = 0;

        xlength = 2;
        ylength = 3;
    }

    void rotate()
    {
        if (rotationNumber == 1)
        {
            delete[] blk;
            definition0();
            rotationNumber = 1;
        }

        else
        {
            delete[] blk;
            definition1();
            rotationNumber = 0;
        }
    }

    Z() { definition0(); }

    ~Z() { delete[] blk; }
};
