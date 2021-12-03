#include <iostream>
using namespace std;

class shape
{
protected:
    int *shape_grid;
    int SHAPE_ROWS;
    int SHAPE_COLS;

public:
    shape(int *);
    void rotateShape();
    virtual void makeShape() = 0;
};