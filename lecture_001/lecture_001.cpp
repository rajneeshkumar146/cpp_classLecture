#include <iostream>
using namespace std;

// g++ lecture_001.cpp -o lecture_001

void prime()
{
	int n;
	cout << "Entre a number: ";
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		bool flag = true;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << i << " ";
		}
	}
}

void isPrime()
{
	int n;
	cout << "Entre a number: ";
	cin >> n;

	bool flag = true;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			flag = false;
			break;
		}
	}

	if (flag)
	{
		cout << "yes " << n << " is Prime." << endl;
	}
	else
	{
		cout << "no " << n << " is not Prime." << endl;
	}
}


void biggest()
{
	int a = 10, b = 30, c = 200;
	if (a >= b && a >= c)
	{
		cout << "biggest: " << a << endl;
	}
	else if (b >= a && b >= c)
	{
		cout << "biggest: " << b << endl;
	}
	else
	{
		cout << "biggest: " << c << endl;
	}
}

void si()
{
	int p = 1000;
	int r = 10;
	int t = 2;
	int ptr = (p * t * r) / 100;

	cout << "simple Interest is " << ptr << endl;
}

void helloworld()
{
	cout << "hello world" << endl;
}

void solve()
{
	helloworld();
	// si();
	// biggest();
	// counter();
	// isPrime();
	// prime();
}

int main(int argc, char const *argv[])
{
	// freopen("C:/Users/Rijnesh/Cpp/input.txt", "r", stdin);
	// freopen("C:/Users/Rijnesh/Cpp/output.txt", "w", stdout);

	solve();
	return 0;
}