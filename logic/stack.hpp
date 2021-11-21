#include "../constant.hpp"
#include <iostream>
using namespace std;

class __stack__
{
private:
    int *stack;

protected:
    int top;

public:
    void pop();
    void push(int, int);
    void showStack();
    int operator[](int);
    void operator=(const __stack__);
    __stack__();
};