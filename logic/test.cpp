#include "block.cpp"

int main()
{
    __block__ peice;

    peice.J();
    peice.show();
    cout << endl;
    ~peice;
    peice.show();
    cout << endl;
    ~peice;
    peice.show();
    cout << endl;
    ~peice;
    peice.show();
    cout << endl;
    ~peice;
    peice.show();
    cout << endl;
    ~peice;
    peice.show();
    return 0;
}