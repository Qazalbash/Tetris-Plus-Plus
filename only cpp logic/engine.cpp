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
            tetromino.row += 1;
            break;
        case 'D':
            if (!isBottomCollision())
            {
                tetromino.row += 1;
            }
            break;
        case 'L':
            if (!wallCollision(false, true))
            {
                tetromino.column -= 1;
            }
            tetromino.row += 1;
            break;
        case 'R':
            if (!wallCollision(true, false) && tetromino.row + tetromino.bottomWallRowNumber + 1 < ROWS)
            {
                tetromino.column += 1;
            }
            tetromino.row += 1;
            break;
        default:
            tetromino.row += 1;
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

    bool wallCollision(bool rightWall = false, bool leftWall = false)
    {
        if (!leftWall && rightWall)
        {
            return tetromino.rightWallColumnNumber + tetromino.column + 1 >= COLS;
        }
        else if (leftWall && !rightWall)
        {
            return tetromino.column + tetromino.leftWallColumnNumber <= 0;
        }

        return false;
    }

    bool isBottomCollision()
    {
        if (tetromino.row + tetromino.bottomWallRowNumber < 19)
        {
            for (int bottomCollisionArrow = 0; bottomCollisionArrow < COLS; bottomCollisionArrow++)
            {
                if (landed[tetromino.bottomWallRowNumber + 1][bottomCollisionArrow] == 1)
                {
                    return true;
                }
            }
        }
        if (tetromino.row + tetromino.bottomWallRowNumber == 19)
        {
            return true;
        }
        return false;
    }

    void renderBlock(int Row, int Col)
    {
        if (!checkCollision())
        {
            for (int renderBlockRowArrow = tetromino.upperWallRowNumber; renderBlockRowArrow <= tetromino.bottomWallRowNumber; renderBlockRowArrow++)
            {
                for (int renderBlockColArrow = tetromino.leftWallColumnNumber; renderBlockColArrow <= tetromino.rightWallColumnNumber; renderBlockColArrow++)
                {
                    playground[renderBlockRowArrow + Row][renderBlockColArrow + Col] = tetromino[renderBlockRowArrow][renderBlockColArrow];
                }
            }
        }
    }

    void blockBuster()
    {
        static bool bustingRow;
        for (int blockBusterRowArrow = ROWS - 1; blockBusterRowArrow >= 0; blockBusterRowArrow--)
        {
            bustingRow = true;
            for (int blockBusterColArrow = 0; blockBusterColArrow < COLS; blockBusterColArrow++)
            {
                if (playground[blockBusterRowArrow][blockBusterColArrow] == 0)
                {
                    bustingRow = false;
                    break;
                }
            }
            if (bustingRow)
            {
                for (int swapRowArrow = blockBusterRowArrow; swapRowArrow >= 0; swapRowArrow--)
                {
                    playground.swap(swapRowArrow - 1, swapRowArrow);
                }
                break;
            }
        }
    }

    __engine__()
    {
        score = 0;
        speed = 1;
        selectPeice();
    }

    // ~__engine__()
    // {
    //     delete[] & playground;
    //     delete[] & landed;
    //     delete[] & tetromino;
    // }

    void refresh()
    {
        for (int playgroundRowArrow = 0; playgroundRowArrow < ROWS; playgroundRowArrow++)
        {
            for (int playgroundColArrow = 0; playgroundColArrow < COLS; playgroundColArrow++)
            {
                playground[playgroundRowArrow][playgroundColArrow] = landed[playgroundRowArrow][playgroundColArrow];
            }
        }
    }

    bool checkCollision()
    {
        if (isBottomCollision())
        {
            landed.update(playground);
            return true;
        }
        return false;
    }
};