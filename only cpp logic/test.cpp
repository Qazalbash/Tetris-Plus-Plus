#include "engine.cpp"
#include <iostream>
using namespace std;

void mainLoop(__engine__ &server)
{
    server.selectPeice();
    while (!server.isBottomCollision())
    {
        cout << server.tetromino.row << " " << server.tetromino.column << endl;
        cout << server.tetromino.row + server.tetromino.bottomWallRowNumber;
        cout << endl;
        server.renderBlock(server.tetromino.row, server.tetromino.column);
        server.tetromino.show();
        cout << endl;
        (server.playground).appear();
        server.refresh();
        server.run();
    }
}

int main()
{
    __engine__ server;
    while (true)
    {
        mainLoop(server);
    }
    return 0;
}