#include "matrix.h"

class Block
{
private:
    int block[4][4];

public:
    void I();
    void J();
    void L();
    void O();
    void S();
    void T();
    void Z();

    void rotate();
    void operator$();

    void show();
};