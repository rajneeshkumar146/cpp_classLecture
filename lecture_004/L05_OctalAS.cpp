// #include <bits/stdc++.h>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

void octalAdd()
{

    int num1, num2;
    cin >> num1 >> num2;
    int res = 0;

    int carry = 0;
    int pow = 1;
    while (num1 != 0 || num2 != 0)
    {
        int addrem = num1 % 10 + num2 % 10 + carry;
        num1 /= 10;
        num2 /= 10;

        carry = addrem / 8;
        addrem %= 8;

        res += addrem * pow;
        pow *= 10;
    }
    res += carry * pow;
    cout << res;
}

void octalSub()
{

    int num1, num2;
    cin >> num1 >> num2;
    int res = 0;
    bool flag=num2>num1?true:false;
    if(flag) swap(num1,num2);

    int borrow = 0;
    int pow = 1;
    while (num1 != 0 || num2 != 0 || borrow != 0)
    {
        int rem = num1 % 10 - num2 % 10 + borrow;
        num1 /= 10;
        num2 /= 10;
        if (rem < 0)
        {
            rem += 8;
            borrow = -1;
        }
        else
        {
            borrow = 0;
        }
        rem %= 8;
        res += rem * pow;
        pow *= 10;
    }

    if(flag) res*=-1;
    cout << res;
}

void solve()
{
    // octalAdd();
    octalSub();
    // cout << "hello";
}
int main()
{

    // freopen("C:/Users/Rijnesh/Cpp/input.txt", "r", stdin);
    // freopen("C:/Users/Rijnesh/Cpp/output.txt","w",stdout);

    solve();

    return 0;
}
