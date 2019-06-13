#include <iostream>
using namespace std;

void solve()
{

    int arr[4] = {10, 20, 30, 40};
    int *p1 = arr;
    int *p2 = &arr[0];
    int(*p3)[4] = &arr;

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    p1++;
    p2++;
    p3++;

    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *(*p3-1) << endl;

    cout << &arr << " " << &arr + 1 << " " << (&arr + 1) - &arr << endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}