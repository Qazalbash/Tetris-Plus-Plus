#include "../constant.hpp"
// #include "stack.hpp"
#include "movement.cpp"

class __screen__ : public __movement__
{
private:
    __stack__ screen[COLS];

public:
    void update();
    void appear();
    __screen__();
};