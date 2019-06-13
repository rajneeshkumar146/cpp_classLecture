// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

void anyToDecimal()
{
    int num;
    cin >> num;
    int base;
    cin >> base;
    int res = 0;
    int pow = 1;
    while (num != 0)
    {
        int rem = num % base;
        num /= base;
        res = res + rem * pow;
        pow *= 10;
    }

    cout << res << endl;
}

void decimalToAny()
{
    int num;
    cin >> num;
    int base;
    cin >> base;
    int res = 0;
    int pow = 1;
    while (num != 0)
    {
        int rem = num % 10;
        num /= 10;
        res = res + rem * pow;
        pow *= base;
    }

    cout << res << endl;
}

void solve()
{
    cout << "hello";
}
int main()
{

    // freopen("C:/Users/Rijnesh/Cpp/input.txt","r",stdin);
    // // freopen("C:/Users/Rijnesh/Cpp/output.txt","w",stdout);

    solve();

    return 0;
}
