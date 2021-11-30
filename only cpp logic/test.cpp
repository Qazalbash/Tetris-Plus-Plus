#include "engine.cpp"
#include <iostream>
using namespace std;

int main()
{
    __engine__ server;

    while (true)
    {
        server.renderBlock(server.tetromino.row, server.tetromino.column);

        (server.playground).appear();

        server.refresh();

        server.run();
    }

    return 0;
}