#include <iostream>
using namespace std;

class shape
{
protected:
    int *shape_grid;
    int SHAPE_ROWS;
    int SHAPE_COLS;

public:
    shape(int, int);
    int *rotateShape();
    // virtual int *makeShape();

    int *makeShapeI();
    int *makeShapeT();
    int *makeShapeJ();
    int *makeShapeL();
    int *makeShapeO();
    int *makeShapeS();
    int *makeShapeZ();

    // ~shape();
};