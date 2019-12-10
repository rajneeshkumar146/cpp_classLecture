#include <iostream>
using namespace std;

void solve()
{

    int i = 10;
    short int j = 20;
    long long int k = 30;

    cout << sizeof(i) << endl;
    cout << sizeof(j) << endl;
    cout << sizeof(k) << endl;

    int *p1 = &i;
    short int *p2 = &j;
    long long int *p3 = &k;

    cout << p1 << " " << p2 << " " << p3 << endl;

    // mutiply by sizeof
    int *p11 = p1 + 5;
    short int *p22 = p2 + 5;
    long long int *p33 = p3 + 5;

    cout << p1 << " " << p11 << endl;
    cout << p2 << " " << p22 << endl;
    cout << p3 << " " << p33 << endl;

    // divide by sizeof
    cout << p11 - p1 << endl;
    cout << p22 - p2 << endl;
    cout << p33 - p3 << endl;

    cout << (char *)p11 - (char *)p1 << endl;
    cout << (char *)p22 - (char *)p2 << endl;
    cout << (char *)p33 - (char *)p3 << endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}