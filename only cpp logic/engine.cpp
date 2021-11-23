#include "screen.cpp"
#include "block.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class __engine__ : public __screen__, public __block__
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
        srand(time(NULL));
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
        playground = new __screen__;
        tempPlayground = new __screen__;
        tetromino = new __block__;
    }
};