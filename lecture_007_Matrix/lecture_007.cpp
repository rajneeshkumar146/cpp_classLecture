#include <iostream>
#include <algorithm>
using namespace std;

const int mr = 100, mc = 100;

void display(int **mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}
void displayBound(int (&mat)[mr][mc], int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int **input(int **mat, int n, int m)
{
    mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        int *arr = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[j];
        }
        mat[i] = arr;
    }

    // display(mat, n, m);
    return mat;
}

void inputBound(int (&mat)[mr][mc], int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void waveDisplay()
{

    // 4 4 u
    // 1 2 3 4
    // 5 6 7 8
    // 9 10 11 12
    // 13 14 15 16

    // 4 4 f
    // 1 2 3 4
    // 5 6 7 8
    // 9 10 11 12
    // 13 14 15 16

    int mat[mr][mc] = {0};
    int n, m;
    char ch;
    cin >> n >> m >> ch;

    inputBound(mat, n, m);
    if (ch != 'u')
        swap(m, n);

    for (int j = 0; j < m; j++)
    {
        if ((j & 1) != 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << ((ch == 'u') ? mat[i][j] : mat[j][i]) << " ";
            }
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << ((ch == 'u') ? mat[i][j] : mat[j][i]) << " ";
            }
        }
    }
}

void spiralDisplay()
{

    // 4 5
    // 0 1 2 3 4
    // 5 6 7 8 9
    // 9 8 7 6 5
    // 4 3 2 1 0

    int mat[mr][mc] = {0};
    int n, m;
    cin >> n >> m;

    inputBound(mat, n, m);

    int toe = n * m;
    int count = 0;
    int minr = 0, minc = 0, maxr = n - 1, maxc = m - 1;

    while (count < toe)
    {

        for (int j = minc; j <= maxc && count < toe; j++)
        {
            cout << mat[minr][j] << " ";
            count++;
        }
        minr++;

        for (int i = minr; i <= maxr && count < toe; i++)
        {
            cout << mat[i][maxc] << " ";
            count++;
        }
        maxc--;

        for (int j = maxc; j >= minc && count < toe; j--)
        {
            cout << mat[maxr][j] << " ";
            count++;
        }
        maxr--;

        for (int i = maxr; i >= minr && count < toe; i--)
        {
            cout << mat[i][minc] << " ";
            count++;
        }
        minc++;
    }
}

void exitPoint()
{

    //    4 4
    //    0 0 0 1
    //    1 0 0 0
    //    0 0 0 0
    //    1 0 0 1

    int n, m;
    cin >> n >> m;
    int **mat = input(mat, n, m);

    int i = 0, j = 0, dir = 0;

    int count = 0;
    int total = n * m;
    while (count < total)
    {

        dir = (dir + mat[i][j]) % 4;
        count++;
        if (dir == 0)
        {
            j++;
            if (j == m)
            {
                j--;
                break;
            }
        }
        else if (dir == 1)
        {
            i++;
            if (i == n)
            {
                i--;
                break;
            }
        }
        else if (dir == 2)
        {
            j--;
            if (j == -1)
            {
                j++;
                break;
            }
        }
        else
        {
            i--;
            if (i == -1)
            {
                i++;
                break;
            }
        }
    }

    cout << "(" << i << ", " << j << ")";
}

void rotate()
{

    // 4 4 r
    // 1 2 3 4
    // 5 6 7 8
    // 9 10 11 12
    // 13 14 15 16

    int mat[mr][mc] = {0};
    int n, m;
    char ch;
    cin >> n >> m >> ch;

    inputBound(mat, n, m);
    displayBound(mat, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    if (ch == 'l')
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            swap(mat[i], mat[j]);
            i++;
            j--;
        }
    }
    else if (ch == 'r')
    {
        int i = 0, j = m - 1;
        while (i < j)
        {
            for (int k = 0; k < n; k++)
            {
                swap(mat[k][i], mat[k][j]);
            }

            i++;
            j--;
        }
    }
    else
    {
        return;
    }

    displayBound(mat, n, m);
}

void solve()
{
    // cout << "hello world" << endl;

    // waveDisplay();
    //  spiralDisplay();
    // exitPoint();
    // rotate();
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}
