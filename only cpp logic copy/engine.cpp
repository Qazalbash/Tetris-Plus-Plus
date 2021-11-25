#include "screen.cpp"
#include "block.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class __engine__ //: public __screen__, public __block__
{
public:
    __screen__ *playground;
    __screen__ *tempPlayground;
    __block__ *tetromino;

    char control()
    {
        char output;
        cout << "Enter the control (U, D, L, R): ";
        cin >> output;
        return output;
    }

    void selectPeice()
    {
        srand((unsigned)time(0));
        int secretNumber = rand() % 7;
        switch (secretNumber)
        {
        case 0:
            tetromino->I();
            break;
        case 1:
            tetromino->J();
            break;
        case 2:
            tetromino->L();
            break;
        case 3:
            tetromino->O();
            break;
        case 4:
            tetromino->S();
            break;
        case 5:
            tetromino->T();
            break;
        case 6:
            tetromino->Z();
            break;
        }
    }

    void run()
    {
        char direction = control();
        switch (direction)
        {
        case 'U':
            ~*tetromino;
            break;
        case 'D':
            break;
        case 'L':
            tetromino->y -= 1;
            break;
        case 'R':
            tetromino->y += 1;
            break;
        default:
            tetromino->x -= 1;
            break;
        }
    }

    __engine__()
    {
        cout << "In constructor" << endl;
        playground = new __screen__;
        tempPlayground = new __screen__;
        tetromino = new __block__;
    }
    ~__engine__()
    {
        delete playground;
        delete tempPlayground;
        delete tetromino;
    }
};

// int main()
// {
//     cout << "I am in main" << endl;
//     __engine__ engine;
//     cout << "I am in main" << endl;
//     return 0;
// }

// int main()
// {
//     __block__ peice;
//     peice.show();

//     return 0;
// }