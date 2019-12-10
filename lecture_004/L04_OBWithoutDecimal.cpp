// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int decimalToBinary(int num)
{
    int res = 0;
    int pow = 1;
    while (num != 0)
    {
        int rem = num % 2;
        num /= 2;
        res = res + rem * pow;
        pow *= 10;
    }

    return res;
}

int binaryToDecimal(int num)
{
    int res = 0;
    int pow = 1;
    while (num != 0)
    {
        int rem = num % 10;
        num /= 10;
        res = res + rem * pow;
        pow *= 2;
    }

    return res;
}

void octalToBinary()
{
    int num;
    cin >> num;
    int res = 0;
    int pow = 1;
    while (num != 0)
    {
        int rem = decimalToBinary(num % 10);
        num /= 10;
        res = res + rem * pow;
        pow *= 1000;
    }

    cout << res << endl;
}

void BinaryToOctal()
{

    int num;
    cin >> num;
    int res = 0;
    int pow = 1;
    while (num != 0)
    {
        int rem = binaryToDecimal(num % 1000);
        num /= 1000;
        res = res + rem * pow;
        pow *= 10;
    }

    cout << res << endl;
}

void solve()
{

    octalToBinary();
    BinaryToOctal();
    // cout << "hello";
}
int main()
{

    // freopen("C:/Users/Rijnesh/Cpp/input.txt","r",stdin);
    // // freopen("C:/Users/Rijnesh/Cpp/output.txt","w",stdout);

    solve();

    return 0;
}
