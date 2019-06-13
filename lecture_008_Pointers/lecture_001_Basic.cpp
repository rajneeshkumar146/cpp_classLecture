#include <iostream>
using namespace std;

void solve()
{

    int a = 10;
    int *p = &a;
    int **q = &p;

    cout << a << " " << &a << endl;
    cout << p << " " << &p << endl;
    cout << *p << " " << &*p << endl;
    cout << q << " " << *q << " " << **q << endl;

    int j=(int)&a; // address ko explicitely decimal mai convert krega.
    cout<< j<<" "<<(int*)j<<endl; //decimal ko address mai convert krega.

}

int main(int argc, char **argv)
{
    solve();
    return 0;
}