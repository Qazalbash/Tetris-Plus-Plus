#include "engine.cpp"
#include <iostream>
using namespace std;

int main()
{
    __engine__ server;
    cout << "down" << endl;
    server.control();
    // server.selectPeice();
    (server.tetromino)->J();

    (server.tetromino)->show();
    cout << endl;
    ~*server.tetromino;
    (server.tetromino)->show();

    return 0;
}

// int main()
// {
//     __block__ peice;
//     peice.show();

//     return 0;
// }