#include <iostream>
using namespace std;

class __block__
{

protected:
    int **blk;

    // int xlength;
    // int ylength;

    // int rotationNumber = 0;

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
    int row;
    int column;

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
        // for (int showRowArrow = 0; showRowArrow < ylength; showRowArrow++)
        // {
        //     for (int showColArrow = 0; showColArrow < xlength; showColArrow++)
        //     {
        //         cout << blk[showRowArrow][showColArrow] << " ";
        //     }
        //     cout << endl;
        // }
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

    // void operator=(__block__ *B)
    // {
    // }

    // virtual void rotate();

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
};

// int main()
// {
//     __block__ peice;
//     peice.Z();
//     peice.show();
//     cout << endl;
//     ~peice;
//     peice.show();
//     cout << endl;
//     ~peice;
//     peice.show();
//     cout << endl;
//     ~peice;
//     peice.show();

//     return 0;
// }

// class I : public __block__
// {
// public:
//     void definition0()
//     {
//         blk = new int *[4];
//         blk[0] = new int[1];
//         blk[1] = new int[1];
//         blk[2] = new int[1];
//         blk[3] = new int[1];

//         blk[0][0] = 1;
//         blk[1][0] = 1;
//         blk[2][0] = 1;
//         blk[3][0] = 1;

//         xlength = 1;
//         ylength = 4;
//     }

//     void definition1()
//     {
//         blk = new int *[1];
//         blk[0] = new int[4];

//         blk[0][0] = 1;
//         blk[0][1] = 1;
//         blk[0][2] = 1;
//         blk[0][3] = 1;

//         xlength = 4;
//         ylength = 1;
//     }

//     void rotate()
//     {
//         delete[] blk;
//         if (rotationNumber == 1)
//         {
//             definition0();
//             rotationNumber = 1;
//         }

//         else
//         {
//             definition1();
//             rotationNumber = 0;
//         }
//     }

//     I() { definition0(); }

//     virtual ~I() { delete[] blk; }
// };

// class J : public __block__
// {
// public:
//     void definition0()
//     {
//         blk = new int *[3];
//         blk[0] = new int[2];
//         blk[1] = new int[2];
//         blk[2] = new int[2];

//         blk[0][0] = 0;
//         blk[0][1] = 1;
//         blk[1][0] = 0;
//         blk[1][1] = 1;
//         blk[2][0] = 1;
//         blk[2][1] = 1;

//         xlength = 2;
//         ylength = 3;
//     }

//     void definition1()
//     {
//         blk = new int *[2];
//         blk[0] = new int[3];
//         blk[1] = new int[3];

//         blk[0][0] = 1;
//         blk[0][1] = 0;
//         blk[0][2] = 0;
//         blk[1][0] = 1;
//         blk[1][1] = 1;
//         blk[1][2] = 1;

//         xlength = 3;
//         ylength = 2;
//     }

//     void definition2()
//     {
//         blk = new int *[3];
//         blk[0] = new int[2];
//         blk[1] = new int[2];
//         blk[2] = new int[2];

//         blk[0][0] = 1;
//         blk[0][1] = 1;
//         blk[1][0] = 1;
//         blk[1][1] = 0;
//         blk[2][0] = 1;
//         blk[2][1] = 0;

//         xlength = 2;
//         ylength = 3;
//     }

//     void definition3()
//     {
//         blk = new int *[2];
//         blk[0] = new int[3];
//         blk[1] = new int[3];

//         blk[0][0] = 1;
//         blk[0][1] = 1;
//         blk[0][2] = 1;
//         blk[1][0] = 0;
//         blk[1][1] = 0;
//         blk[1][2] = 1;

//         xlength = 3;
//         ylength = 2;
//     }

//     void rotate()
//     {
//         delete[] blk;
//         switch (rotationNumber)
//         {
//         case 0:
//             definition1();
//             rotationNumber = 1;
//             break;

//         case 1:
//             definition2();
//             rotationNumber = 2;
//             break;

//         case 2:
//             definition3();
//             rotationNumber = 3;
//             break;

//         case 3:
//             definition0();
//             rotationNumber = 0;
//             break;
//         }
//     }

//     J() { definition0(); }

//     virtual ~J() { delete[] blk; }
// };

// class L : public __block__
// {
// public:
//     void definition0()
//     {
//         blk = new int *[3];
//         blk[0] = new int[2];
//         blk[1] = new int[2];
//         blk[2] = new int[2];

//         blk[0][0] = 1;
//         blk[0][1] = 0;
//         blk[1][0] = 1;
//         blk[1][1] = 0;
//         blk[2][0] = 1;
//         blk[2][1] = 1;

//         xlength = 2;
//         ylength = 3;
//     }

//     void definition1()
//     {
//         blk = new int *[2];
//         blk[0] = new int[3];
//         blk[1] = new int[3];

//         blk[0][0] = 1;
//         blk[0][1] = 0;
//         blk[0][2] = 0;
//         blk[1][0] = 1;
//         blk[1][1] = 1;
//         blk[1][2] = 1;

//         xlength = 3;
//         ylength = 2;
//     }

//     void definition2()
//     {
//         blk = new int *[3];
//         blk[0] = new int[2];
//         blk[1] = new int[2];
//         blk[2] = new int[2];

//         blk[0][0] = 1;
//         blk[0][1] = 1;
//         blk[1][0] = 0;
//         blk[1][1] = 1;
//         blk[2][0] = 0;
//         blk[2][1] = 1;

//         xlength = 2;
//         ylength = 3;
//     }

//     void definition3()
//     {
//         blk = new int *[2];
//         blk[0] = new int[3];
//         blk[1] = new int[3];

//         blk[0][0] = 0;
//         blk[0][1] = 0;
//         blk[0][2] = 1;
//         blk[1][0] = 1;
//         blk[1][1] = 1;
//         blk[1][2] = 1;

//         xlength = 3;
//         ylength = 2;
//     }

//     void rotate()
//     {
//         delete[] blk;
//         switch (rotationNumber)
//         {
//         case 0:
//             definition1();
//             rotationNumber = 1;
//             break;

//         case 1:
//             definition2();
//             rotationNumber = 2;
//             break;

//         case 2:
//             definition3();
//             rotationNumber = 3;
//             break;

//         case 3:
//             definition0();
//             rotationNumber = 0;
//             break;
//         }
//     }

//     L() { definition0(); }

//     virtual ~L() { delete[] blk; }
// };

// class O : public __block__
// {
// public:
//     void rotate() {}

//     O()
//     {
//         blk = new int *[2];
//         blk[0] = new int[2];
//         blk[1] = new int[2];

//         blk[0][0] = 1;
//         blk[0][1] = 1;
//         blk[1][0] = 1;
//         blk[1][1] = 1;

//         xlength = 2;
//         ylength = 2;
//     }

//     virtual ~O() { delete[] blk; }
// };

// class S : public __block__
// {
// public:
//     void definition0()
//     {
//         blk = new int *[2];
//         blk[0] = new int[3];
//         blk[1] = new int[3];

//         blk[0][0] = 0;
//         blk[0][1] = 1;
//         blk[0][2] = 1;
//         blk[1][0] = 1;
//         blk[1][1] = 1;
//         blk[1][2] = 0;

//         xlength = 3;
//         ylength = 2;
//     }

//     void definition1()
//     {
//         blk = new int *[3];
//         blk[0] = new int[2];
//         blk[1] = new int[2];
//         blk[2] = new int[2];

//         blk[0][0] = 1;
//         blk[0][1] = 0;
//         blk[1][0] = 1;
//         blk[1][1] = 1;
//         blk[2][0] = 0;
//         blk[2][1] = 1;

//         xlength = 2;
//         ylength = 3;
//     }

//     void rotate()
//     {
//         delete[] blk;
//         if (rotationNumber == 1)
//         {
//             definition0();
//             rotationNumber = 1;
//         }

//         else
//         {
//             definition1();
//             rotationNumber = 0;
//         }
//     }

//     S() { definition0(); }

//     virtual ~S() { delete[] blk; }
// };

// class T : public __block__
// {

// public:
//     void definition0()
//     {
//         blk = new int *[2];
//         blk[0] = new int[3];
//         blk[1] = new int[3];

//         blk[0][0] = 0;
//         blk[0][1] = 1;
//         blk[0][2] = 0;
//         blk[1][0] = 1;
//         blk[1][1] = 1;
//         blk[1][2] = 1;

//         xlength = 3;
//         ylength = 2;
//     }

//     void definition1()
//     {
//         blk = new int *[3];
//         blk[0] = new int[2];
//         blk[1] = new int[2];
//         blk[2] = new int[2];

//         blk[0][0] = 1;
//         blk[0][1] = 0;
//         blk[1][0] = 1;
//         blk[1][1] = 1;
//         blk[2][0] = 1;
//         blk[2][1] = 0;

//         xlength = 2;
//         ylength = 3;
//     }

//     void definition2()
//     {
//         blk = new int *[2];
//         blk[0] = new int[3];
//         blk[1] = new int[3];

//         blk[0][0] = 1;
//         blk[0][1] = 1;
//         blk[0][2] = 1;
//         blk[1][0] = 0;
//         blk[1][1] = 1;
//         blk[1][2] = 0;

//         xlength = 3;
//         ylength = 2;
//     }

//     void definition3()
//     {
//         blk = new int *[3];
//         blk[0] = new int[2];
//         blk[1] = new int[2];
//         blk[2] = new int[2];

//         blk[0][0] = 0;
//         blk[0][1] = 1;
//         blk[1][0] = 1;
//         blk[1][1] = 1;
//         blk[2][0] = 0;
//         blk[2][1] = 1;

//         xlength = 2;
//         ylength = 3;
//     }

//     void rotate()
//     {
//         delete[] blk;
//         switch (rotationNumber)
//         {
//         case 0:
//             definition1();
//             rotationNumber = 1;
//             break;

//         case 1:
//             definition2();
//             rotationNumber = 2;
//             break;

//         case 2:
//             definition3();
//             rotationNumber = 3;
//             break;

//         case 3:
//             definition0();
//             rotationNumber = 0;
//             break;
//         }
//     }

//     T() { definition0(); }

//     virtual ~T() { delete[] blk; }
// };

// class Z : public __block__
// {

// public:
//     void definition0()
//     {
//         blk = new int *[2];
//         blk[0] = new int[3];
//         blk[1] = new int[3];

//         blk[0][0] = 1;
//         blk[0][1] = 1;
//         blk[0][2] = 0;
//         blk[1][0] = 0;
//         blk[1][1] = 1;
//         blk[1][2] = 1;

//         xlength = 3;
//         ylength = 2;
//     }

//     void definition1()
//     {
//         blk = new int *[3];
//         blk[0] = new int[2];
//         blk[1] = new int[2];
//         blk[2] = new int[2];

//         blk[0][0] = 0;
//         blk[0][1] = 1;
//         blk[1][0] = 1;
//         blk[1][1] = 1;
//         blk[2][0] = 1;
//         blk[2][1] = 0;

//         xlength = 2;
//         ylength = 3;
//     }

//     void rotate()
//     {
//         delete[] blk;
//         if (rotationNumber == 1)
//         {
//             definition0();
//             rotationNumber = 1;
//         }

//         else
//         {
//             definition1();
//             rotationNumber = 0;
//         }
//     }

//     Z() { definition0(); }

//     virtual ~Z() { delete[] blk; }
// };