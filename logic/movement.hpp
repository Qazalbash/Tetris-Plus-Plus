#include "block.cpp"
#include "stack.cpp"

class __movement__ : public __stack__, public __block__
{
protected:
    float spead;
    bool drop;

public:
    void dropBlock();
    void speadUp();
    bool collision(__stack__, __block__);
    __movement__();
};