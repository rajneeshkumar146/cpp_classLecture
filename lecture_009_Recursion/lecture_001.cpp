#include <iostream>
using namespace std;

#define ll long long int

void printInreasing(int n)
{
    if (n == 0)
        return;
    printInreasing(n - 1);
    cout << n << endl;
}

void printDecreasing(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    printDecreasing(n - 1);
}

void printIncrDecre(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    printIncrDecre(n - 1);
    cout << n << endl;
}

void printOddEven(int n)
{
    if (n == 0)
        return;

    if ((n & 1) != 0)
        cout << n << endl;

    printOddEven(n - 1);

    if ((n & 1) == 0)
        cout << n << endl;
}

int printZZ(int n)
{
    if (n == 0)
        return 0;

    int ans = 0;

    cout << "pre"
         << " " << n << endl;
    ans += printZZ(n - 1);

    cout << "In"
         << " " << n << endl;

    ans += printZZ(n - 1);
    cout << "post"
         << " " << n << endl;

    return ans + 3;
}

void toh(int n, char src, char desti, char help)
{
    if (n == 0)
        return;

    toh(n - 1, src, help, desti);
    cout << "nth disck: " << n << " "
         << "from " << src << " to " << desti << endl;
    toh(n - 1, help, desti, src);
}

int fact(int n)
{
    return (n == 0 || n == 1) ? n : n * fact(n - 1);
}

int power(int a, int b)
{
    return (b == 0 || a == 0) ? 1 : a * power(a, b - 1);
}

ll powerBtr(int a, int b)
{

    if (a == 0 || b == 0)
        return 1;

    int smallAns = powerBtr(a, b / 2);
    smallAns *= smallAns;

    if ((b & 1) != 0)
        smallAns *= a;

    return smallAns;
}

void solve()
{
    // printInreasing(5);
    // printDecreasing(5);
    // printIncrDecre(5);
    // printOddEven(6);

    // int n;
    // cin >> n;
    // cout << printZZ(n) << endl;
    // toh(n, 's', 'd', 'h');

    // cout << fact(5) << endl;
    // cout << power(2, 10) << endl;
    // cout<<powerBtr(3,3)<<endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}