#include <iostream>
#include <algorithm>
using namespace std;

int octalAdd(int num1, int num2)
{
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
    return res;
}

void octalMulti()
{
    int num1, num2;
    cin >> num1 >> num2;

    int sumRes = 0;
    int sumPow = 1;

    while (num2 != 0)
    {
        int temp = num1;
        int carry = 0;
        int pow = 1;
        int res = 0;

        int rem2 = num2 % 10;

        while (num1 != 0 || carry != 0)
        {
            int rem = ((num1 % 10) * rem2) + carry;
            num1 /= 10;

            carry = rem / 8;
            rem %= 8;

            res += rem * pow;
            pow *= 10;
        }
        num2 /= 10;
        num1 = temp;
        cout << res << endl;
        sumRes = octalAdd(sumRes, res * sumPow);
        sumPow *= 10;
    }

    cout << sumRes << endl;
}

void solve()
{

    octalMulti();
}

int main(int argc, char **argv)
{

    solve();

    return 0;
}
