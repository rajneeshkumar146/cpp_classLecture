// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int numLeng(int x) {
	int len = 0;

	while (x != 0) {
		len++;
		x /= 10;
	}

	return len;
}

int rotate() {
	int x, r, len;
	cin >> x >> r;
	len = numLeng(x);
	r = r % len;
	r = r < 0 ? r + len : r;

	int mul = 1, div = 1;
	for (int i = 1; i <= len; i++) {
		if (i <= r) {
			div *= 10;
		} else {
			mul *= 10;
		}

	}

	return (x % div) * mul + (x / div);

}

int reverse() {
	int x, len;
	cin >> x;
	len = numLeng(x);
	int rev = 0;

	while (x != 0) {
		rev = (rev) * 10 + x % 10;
		x = x / 10;
	}

	return rev;
}

void lightPuzzle() {
	int x;
	cin >> x;
	vector<int> arr(x, 0);

	for (int i = 1; i * i <= x; i++) {
		for (int j = i; j <= x; j += j) {
			arr[i] = (arr[i] + 1) % 2;
		}
	}

	for (int i = 1; i <= x; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

}


void solve()
{
	// cout<<"hello";
	// cout << rotate() << endl;
	cout << reverse() << endl;
}

int main()
{

	// freopen("C:/Users/Rijnesh/Cpp/input.txt", "r", stdin);
	// freopen("C:/Users/Rijnesh/Cpp/output.txt", "w", stdout);


	solve();

	return 0;
}
