#include "matrix.h"

class Block
{
private:
    int xCord;
    int yCord;

public:
    Block(int randomNo);

    void draw();

    void fall();

    //debugging functions
    void status();
};