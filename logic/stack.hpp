#include "constant.hpp"

class __stack__
{
private:
    int stack[ROWS];

protected:
    int top;

public:
    void pop();
    void push(int, int);
    __stack__();
};