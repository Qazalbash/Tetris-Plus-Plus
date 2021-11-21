#include "constant.hpp"
#include "stack.hpp"
#include "movement.hpp"

class __screen__ : public __movement__
{
private:
    __stack__ screen[10];

public:
    void update();
    __screen__();
};