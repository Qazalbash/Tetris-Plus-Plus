#include "movement.hpp"

void __movement__::dropBlock()
{
    drop = true;
}

void __movement__::speadUp()
{
    spead *= 1.01;
}

__movement__::__movement__()
{
    drop = false;
    spead = 1.0;
}

bool __movement__::collision(__stack__ column, __block__ peice)
{
    return 0;
}