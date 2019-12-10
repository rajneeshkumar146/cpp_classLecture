// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

void ocatalToDecimal()
{
    int num;
    cin >> num;
    int res = 0;
    int pow = 1;
    while (num != 0)
    {
        int rem = num % 10;
        num /= 10;
        res = res + rem * pow;
        pow *= 8;
    }

    cout << res << endl;
}

void decimalToOctal()
{
    int num;
    cin >> num;
    int res = 0;
    int pow = 1;
    while (num != 0)
    {
        int rem = num % 8;
        num /= 8;
        res = res + rem * pow;
        pow *= 10;
    }

    cout << res << endl;
}

void solve()
{
    decimalToOctal();
    ocatalToDecimal();
    // cout << "hello";
}
int main()
{

    // freopen("C:/Users/Rijnesh/Cpp/input.txt","r",stdin);
    // // freopen("C:/Users/Rijnesh/Cpp/output.txt","w",stdout);

    solve();

    return 0;
}
