#include <iostream>
#include <algorithm>

using namespace std;

void allBits(int x)
{

    for (int i = 31; i >= 0; i--)
    {
        int mask = (1 << i);
        if ((x & mask) != 0)
            cout << 1;
        else
            cout << 0;
    }
    cout<< endl;
}

int onBit(int x, int pos)
{
    int mask = (1 << pos);
    x |= mask;
    return x;
}

int offBit(int x, int pos)
{
    int mask = ~(1 << pos);
    x &= mask;
    return x;
}



void solve()
{
    int x, pos;
    cin >> x;
    cin >> pos;

    allBits(x);

    // x = onBit(x, pos);
    // x=offBit(x,pos);


    allBits(x);
}

int main(int argc, char **argv)
{

    solve();
    return 0;
}