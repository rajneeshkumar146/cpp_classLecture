// #include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
    int dec = 0;
	int db;
    int dn = 0;

    cin >> dec >> db;
    
    int p = 1;
    while(dec != 0){
        int r = dec % db;
        dec = dec / db;

        dn += r * p;
        p = p * 10;
    }

    cout << dn ;
}
