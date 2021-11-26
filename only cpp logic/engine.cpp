#include "screen.cpp"
#include "block.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class __engine__
{
public:
    __screen__ playground;
    __screen__ landed;
    __block__ tetromino;
    int speed;
    int score;

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
            tetromino.I();
            break;
        case 1:
            tetromino.J();
            break;
        case 2:
            tetromino.L();
            break;
        case 3:
            tetromino.O();
            break;
        case 4:
            tetromino.S();
            break;
        case 5:
            tetromino.T();
            break;
        case 6:
            tetromino.Z();
            break;
        }
    }

    void run()
    {
        char direction = control();
        switch (direction)
        {
        case 'U':
            ~tetromino;
            break;
        case 'D':
            tetromino.x += 1;
            break;
        case 'L':
            tetromino.y -= 1;
            tetromino.x += 1;
            break;
        case 'R':
            tetromino.y += 1;
            tetromino.x += 1;
            break;
        default:
            tetromino.x += 1;
            break;
        }
    }

    void increaseSpeed()
    {
        speed *= 1.01;
    }

    void increaseScore()
    {
        score += speed * 100;
    }

    bool wallCollision(bool rightWall = false, bool leftWall = false, int rightColumn = 0, int leftColumn = 4)
    {
        if (rightWall)
        {
            for (int wallCollisionRowArrow = 0; wallCollisionRowArrow < 5; wallCollisionRowArrow++)
            {
                        }
        }
    }

    // bool blockCollision()
    // {
    // }

    void renderBlock(int xCord, int yCord)
    {
        for (int renderBlockRowArrow = xCord; renderBlockRowArrow < xCord + 5; renderBlockRowArrow++)
        {
            for (int renderBlockColArrow = yCord; renderBlockColArrow < yCord + 5; renderBlockColArrow++)
            {
                landed[renderBlockRowArrow][renderBlockColArrow] = tetromino[renderBlockRowArrow - xCord][renderBlockColArrow - yCord];
            }
        }
    }

    __engine__()
    {
        score = 0;
        speed = 1;
        selectPeice();
    }
};