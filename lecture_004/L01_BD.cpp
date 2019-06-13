// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

void decimalToBinary()
{
    int x;
    cin >> x;
    int res = 0;
    int pow = 1;
    while (x != 0)
    {
        int rem = x % 2;
        x /= 2;
        res = res + rem * pow;
        pow *= 10;
    }

    cout << res << endl;
}

void binaryToDecimal()
{
    int x;
    cin >> x;
    int res = 0;
    int pow = 1;
    while (x != 0)
    {
        int rem = x % 10;
        x /= 10;
        res = res + rem * pow;
        pow *= 2;
    }

    cout << res << endl;
}

void solve()
{

    decimalToBinary();
    binaryToDecimal();
    // cout << "hello";
}
int main()
{

    // freopen("C:/Users/Rijnesh/Cpp/input.txt","r",stdin);
    // // freopen("C:/Users/Rijnesh/Cpp/output.txt","w",stdout);

    solve();

    return 0;
}
