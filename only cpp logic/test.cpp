#include "engine.cpp"
#include <iostream>
using namespace std;

void mainLoop(__engine__ &server)
{
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
    server.landed.update(server.playground);
    server.selectPeice();
    server.tetromino.row = 0;
    server.tetromino.column = 2;
}

int main()
{
    __engine__ server;
    while (true)
    {
        mainLoop(server);
        cout << endl
             << "Its landed" << endl;
        server.landed.appear();
    }
    return 0;
}