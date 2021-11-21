#include "block.hpp"

class __movement__ : public __block__
{
protected:
    float spead;
    bool drop;

public:
    void dropBlock();
    void speadUp();
    __movement__();
};