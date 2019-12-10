// #include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
	int sb;
    int sn;

    cin >> sn >> sb;

    int dec = 0;
    int p = 1;
    while(sn != 0){
        int r = sn % 10;
        sn = sn / 10;

        dec += r * p;
        p = p * sb;
    }

    cout << dec << endl;
}
