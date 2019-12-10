// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int d = 2; d < n; d++){
        if(n % d == 0){
            cout << 0;
            return;
        }
    }

    cout << 1;
}
