#include "../constant.hpp"
#include <iostream>
using namespace std;

class __stack__
{
private:
    int stack[ROWS];

protected:
    int top;

public:
    void pop();
    void push(int, int);
    void showStack();
    __stack__();
};