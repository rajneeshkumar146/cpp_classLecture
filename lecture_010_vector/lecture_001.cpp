#include <iostream>
#include <vector>
using namespace std;

//1. vect.push_back(): for append element in vector.
//2. vect.size(): Give Size of vector.
//3. vect.capacity(): prvide exact size of vector.

vector<int> insert()
{
    vector<int> vec;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i * 2);
    }

    cout << "Size: " << vec.size() << "\nCapacity: " << vec.capacity() << endl;

    return vec;
}

void display(vector<int> &vect)
{
    //class iterator
    for (auto i = vect.begin(); i != vect.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;

    //iterator
    for (int i : vect)
    {
        cout << i << " ";
    }
}

void solve()
{

    vector<int> vec;
    vec = insert();
    display(vec);
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}