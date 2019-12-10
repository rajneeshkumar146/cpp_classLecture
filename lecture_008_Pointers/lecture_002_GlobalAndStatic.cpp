#include <iostream>
using namespace std;

// int *wfun()
// {
//     int x = 10;
//     return &x;
// }

void stackDirection(int x)
{
    if (x == 0)
        return;
    cout << &x << endl;
    stackDirection(x - 1);
}
int *sfun()
{
    static int x = 10;
    return &x;
}

void wLoop()
{
    int x = 10;
    x++;
    cout << x << endl;
}

void sLoop()
{
    static int x = 10;
    x++;
    cout << x << endl;
}

void solve()
{
    // int *w = wfun();    // wrong because x is now doesnot exist.
    // cout << *w << endl; //error or unexpected behavious.

    //    stackDirection(4);

    // int *s = sfun();
    // cout << s << " " << *s << endl;

    for(int i=0;i<5;i++){
        wLoop();
        sLoop();
    }
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}