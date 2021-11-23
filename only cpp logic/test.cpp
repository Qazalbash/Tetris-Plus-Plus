#include "engine.cpp"
// #include <iostream>
// using namespace std;

int main()
{
    __engine__ server;
    // server.control();
    server.selectPeice();
    server.tetromino->show();
    cout << endl;
    ~*server.tetromino;
    server.tetromino->show();
    return 0;
}