#include "../constant.hpp"
#include "movement.cpp"
#include <iostream>
using namespace std;

class __screen__ : public __movement__
{
private:
    __stack__ *screen;

public:
    void update(__screen__);
    void appear();
    __stack__ operator[](int);
    __screen__();
};