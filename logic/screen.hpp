#include "../constant.hpp"
#include "movement.cpp"

class __screen__ : public __movement__
{
private:
    __stack__ **screen;

public:
    void update(__screen__ **);
    void appear();
    // void operator=(__block__);
    __screen__();
};