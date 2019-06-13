#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void takeinput(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

bool find(int *arr, int n, int data)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == data)
            return true;
    }

    return false;
}

int firstIndex(int *arr, int n, int data)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == data)
            return i;
    }

    return -1;
}

int lastIndex(int *arr, int n, int data)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == data)
            return i;
    }

    return -1;
}

void allIndex(int *arr, int n, int data)
{
    bool flag = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == data)
        {
            cout << i << " ";
            flag = true;
        }
    }

    if (!flag)
        cout << -1 << endl;
}

int binarySearch(int *arr, int n, int data)
{

    int lo = 0;
    int hi = n - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;

        if (arr[mid] == data)
            return mid;
        else if (data > arr[mid])
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int binarySearchLowerBound(int *arr, int n, int data)
{
    int lo = 0;
    int hi = n - 1;
    int ans = -1;

    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;

        if (arr[mid] == data)
        {
            ans = mid;
            if ((mid - 1) >= 0 && arr[mid - 1] == data)
                hi = mid - 1;
            else
                return ans;
        }
        else if (arr[mid] > data)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
}

int binarySearchUpperBound(int *arr, int n, int data)
{
    int lo = 0;
    int hi = n - 1;
    int ans = -1;

    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;

        if (arr[mid] == data)
        {
            ans = mid;
            if ((mid + 1) < n && arr[mid + 1] == data)
                hi = mid + 1;
            else
                return ans;
        }
        else if (arr[mid] > data)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
}

void kadanesAlgo(int *arr, int n)
{
    int maxLen = 0;
    int maxSum=0;

    int currLen = 0;

    int currSum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        currLen++;
        if (sum > currSum)
        {
            currSum = sum;

        }
        if (sum <= 0)
        {
            currLen=1;
        }
    }
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(int *arr, int lo, int hi)
{
    while (lo <= hi)
    {
        swap(arr, lo, hi);
        lo++;
        hi--;
    }
}

void rotate(int *arr, int n, int r)
{

    r = r % n;
    r = r < 0 ? r + n : r;

    int *temp = new int[n];

    int idx = 0;
    for (int i = r; i < n; i++)
    {
        temp[idx] = arr[i];
        idx++;
    }

    for (int i = 0; i < r; i++)
    {
        temp[idx] = arr[i];
        idx++;
    }
}

void rotateBest(int *arr, int n, int r)
{
    r = r % n;
    r = r < 0 ? r + n : r;

    reverse(arr, 0, r - 1);
    reverse(arr, r, n - 1);
    reverse(arr, 0, n - 1);
}

void inverse(int *arr, int n)
{

    int temp[100];
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]] = i;
    }

    display(temp, n);
}

bool isInverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[arr[i]] != i)
            return false;
    }
    return true;
}

void solve()
{

    // 10 10 20 30 40 50 60 70 80 90 100
    // 10 6 34 67 76 67 34 43 43 32 45
    int n, data;
    cin >> n;
    int arr[100];

    takeinput(arr, n);

    // cin >> data;
    // cout << binarySearch(arr, n, data) << endl;
    // cout << (boolalpha) << find(arr, n, data) << endl;
    // cout << firstIndex(arr, n, data) << endl;
    // cout << lastIndex(arr, n, data) << endl;
    // allIndex(arr, n, data);

    // reverse(arr, 0, n - 1);
    // display(arr, n);

    // 10 6 34 67 76 67 34 43 43 32 45 365
    // int r;
    // cin >> r;
    // rotateBest(arr, n, r);
    // rotate(arr, n, r);
    // display(arr, n);

    // 5 4 2 0 1 3
    // inverse(arr, n);
    cout << (boolalpha) << isInverse(arr, n);
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}