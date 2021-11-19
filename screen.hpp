#include "constant.hpp"
#include "stack.hpp"

class __screen__
{
private:
    __stack__ screen[10];

public:
    void update();
    __screen__();
};