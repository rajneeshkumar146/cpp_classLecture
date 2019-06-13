#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void display(int *arr, int n, int vidx)
{
    if (vidx == n)
        return;

    cout << arr[vidx] << endl;
    display(arr, n, vidx + 1);
}

void reverseDisplay(int *arr, int n, int vidx)
{
    if (vidx == n)
        return;

    reverseDisplay(arr, n, vidx + 1);
    cout << arr[vidx] << endl;
}

int maximum(int *arr, int n, int vidx)
{
    if (vidx == n)
        return INT_MIN;
    return max(maximum(arr, n, vidx + 1), arr[vidx]);
}

int minimum(int *arr, int n, int vidx)
{
    if (vidx == n)
        return INT_MAX;
    return min(minimum(arr, n, vidx + 1), arr[vidx]);
}

bool find(int *arr, int n, int data, int vidx)
{
    if (vidx == n)
        return false;

    return (arr[vidx] == data) ? true : find(arr, n, data, vidx + 1);
}

int sidx(int *arr, int n, int data, int vidx)
{
    if (vidx == n)
        return -1;

    return (arr[vidx] == data) ? vidx : sidx(arr, n, data, vidx + 1);
}

int lidx(int *arr, int n, int data, int vidx)
{
    if (vidx == n)
        return -1;

    int idx = lidx(arr, n, data, vidx + 1);
    return (idx != -1) ? idx : (arr[vidx] == data) ? vidx : -1;
}

int *allidx(int *arr, int n, int data, int vidx, int count, int *size)
{
    if (vidx == n)
    {
        (*size) = count;
        return new int[count];
    }

    if (arr[vidx] == data)
    {
        int *ans = allidx(arr, n, data, vidx + 1, count + 1, size);
        ans[count] = vidx;
        return ans;
    }
    else
    {
        return allidx(arr, n, data, vidx + 1, count, size);
    }
}

void solve()
{
    int *arr = new int[8];
    arr[0] = 2;
    arr[1] = 6;
    arr[2] = 3;
    arr[3] = 9;
    arr[4] = 2;
    arr[5] = 2;
    arr[6] = 9;
    arr[7] = 10;

    int n = 8;
    // cout<<n<<endl;
    // display(arr, n, 0);
    // reverseDisplay(arr,n,0);

    // cout << maximum(arr, n, 0) << endl;
    // cout << minimum(arr, n, 0) << endl;

    // int data;
    // cin >> data;
    // cout << (boolalpha) << find(arr, n, data, 0) << endl;
    // cout << sidx(arr, n, data, 0) << endl;
    // cout << lidx(arr, n, data, 0) << endl;

    // int size=0;
    // int* ans=allidx(arr,n,data,0,0,&size);
    // display(ans,size,0);
    // delete[] ans;

    delete[] arr;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}