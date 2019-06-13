// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

void triangle()
{

	int row;
	cin >> row;
	int nst = 1;
	while (row-- > 0)
	{
		for (int cst = 1; cst <= nst; cst++)
		{
			cout << "*";
		}

		nst++;
		cout << endl;
	}
}

void NumberTraingle()
{

	int row;
	cin >> row;
	int nst = 1;
	int count = 1;
	while (row-- > 0)
	{
		for (int cst = 1; cst <= nst; cst++)
		{
			cout << count++ << " ";
		}

		nst++;
		cout << endl;
	}
}

void fibboPattern()
{

	int row;
	cin >> row;
	int nst = 1;
	int a = 1;
	int b = 0;
	while (row-- > 0)
	{
		for (int cst = 1; cst <= nst; cst++)
		{
			cout << b << " ";
			int sum = b + a;
			a = b;
			b = sum;
		}

		nst++;
		cout << endl;
	}
}

void binomialPattern()
{
	int row;
	cin >> row;
	for (int i = 0; i < row; i++)
	{
		int val = 1;
		for (int j = 0; j <= i; j++)
		{
			cout << val;
			val = val * (i - j) / (j + 1);
		}
		cout << endl;
	}
}

void crossPattern()
{
	int row;
	cin >> row;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= row; j++)
		{
			if ((i == j) || ((i + j) == (row + 1)))
				cout << "*";
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

void daimondPattern()
{
	int row;
	cin >> row;
	row = row & 1 ? row : row + 1;
	int nst = 1;
	int nsp = row / 2;

	for (int r = 1; r <= row; r++)
	{
		for (int csp = 1; csp <= nsp; csp++)
		{
			cout << " ";
		}

		for (int cst = 1; cst <= nst; cst++)
		{
			cout << "*";
		}

		if (r <= row / 2)
		{
			nsp--;
			nst += 2;
		}
		else
		{
			nst -= 2;
			nsp++;
		}
		cout << endl;
	}
}

void hollowDiamond()
{
	int row;
	cin >> row;
	row = row & 1 ? row : row + 1;
	int nsp = 1;
	int nst = row / 2;

	for (int r = 1; r <= row; r++)
	{
		for (int cst = 1; cst <= nst; cst++)
		{
			cout << "*";
		}

		for (int csp = 1; csp <= nsp; csp++)
		{
			cout << " ";
		}

		for (int cst = 1; cst <= nst; cst++)
		{
			cout << "*";
		}

		if (r <= row / 2)
		{
			nst--;
			nsp += 2;
		}
		else
		{
			nsp -= 2;
			nst++;
		}
		cout << endl;
	}
}

void numberDiamond()
{

	int row;
	cin >> row;
	row = row & 1 ? row : row + 1;
	int nst = 1;
	int nsp = row / 2;
	for (int r = 1; r <= row; r++)
	{
		for (int csp = 1; csp <= nsp; csp++)
		{
			cout << " ";
		}

		int var = r < (row + 1) / 2 ? r : row - r + 1;
		for (int cst = 1; cst <= nst; cst++)
		{
			cout << var;
			var = cst < (row + 1) / 2 ? var + 1 : var - 1;
		}

		if (r <= row / 2)
		{
			nsp--;
			nst += 2;
		}
		else
		{
			nst -= 2;
			nsp++;
		}
		cout << endl;
	}
}

void bonousQuestion()
{
	int row;
	cin >> row;
	int nst = 1;
	int nsp = 2 * row - 3;

	int count = 1;
	for (int r = 1; r <= row; r++)
	{
		for (int cst = 1; cst <= nst; cst++)
		{
			cout << count;
			count++;
		}

		for (int csp = 1; csp <= nsp; csp++)
		{
			cout << " ";
		}

		if (r == row)
		{
			count--;
			nst--;
		}

		for (int cst = 1; cst <= nst; cst++)
		{
			count--;
			cout << count;
		}

		nst++;
		nsp -= 2;
		cout << endl;
	}
}

void input(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void bonus2()
{
	int x;
	cin >> x;
	int *arr = new int[x];
	input(arr, x);

	int maxe = INT_MIN;
	for (int i = 0; i < x; i++)
	{
		maxe = max(maxe, arr[i]);
	}

	for (int i = 1; i <= maxe; i++)
	{
		for (int j = 0; j < x; j++)
		{
			int nsp = maxe - arr[j];
			if (nsp <= 0)
				cout << "* ";
			else
				cout << "  ";

			arr[j]++;
		}
		cout << endl;
	}
}

void solve()
{
	// cout << "hello";
	// triangle();
	// NumberTraingle();
	// fibboPattern();
	// binomialPattern();
	// crossPattern();
	// daimondPattern();
	// hollowDiamond();
	// numberDiamond();
	// bonousQuestion();
	// bonus2();
}

int main()
{

	// freopen("C:/Users/Rijnesh/Cpp/input.txt", "r", stdin);
	// freopen("C:/Users/Rijnesh/Cpp/output.txt", "w", stdout);

	solve();

	return 0;
}
