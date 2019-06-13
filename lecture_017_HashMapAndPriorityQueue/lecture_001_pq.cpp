#include <iostream>
#include <queue>
using namespace std;

#define pair pair<int, pair<int, int>>

//generalFunctions.==============================================

void pqfunctions()
{
    // priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq; // reverse Priority Queue.

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    cout << "size: " << pq.size() << endl;
    cout << "top: " << pq.top() << endl;
    pq.pop();
    cout << "top: " << pq.top() << endl;
    cout << "size: " << pq.size() << endl;
}

void dipslay(priority_queue<int> &pq)
{
    while (pq.size() != 0)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void dipslayR(priority_queue<int, vector<int>, greater<int>> &pq)
{
    while (pq.size() != 0)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

//questionSet1.==========================================================

void kSmallest(vector<int> &arr, int k)
{
    priority_queue<int> pq;
    int i = 0;
    while (i < k)
    {
        pq.push(arr[i]);
        i++;
    }

    while (i < arr.size())
    {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
        i++;
    }

    dipslay(pq);
}

void kLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    while (i < k)
    {
        pq.push(arr[i]);
        i++;
    }

    while (i < arr.size())
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
        i++;
    }

    dipslayR(pq);
}

void almostSortedWithKshift(int *kShiftArr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(kShiftArr, kShiftArr + k + 1);
    int i = k + 1;
    while (pq.size() != 0)
    {
        cout << pq.top() << " ";
        pq.pop();
        if (i < n)
        {
            pq.push(kShiftArr[i]);
            i++;
        }
    }
}

void questionSet1()
{
    // vector<int> arr{10, 15, 2, 17, 7, 18, 22, 9, 3};
    // kSmallest(arr, 4);
    // kLargest(arr, 4);

    int kShiftArr[] = {2, 6, 3, 12, 56, 8};
    almostSortedWithKshift(kShiftArr, 6, 3);
}

//questionSet2.======================================================

void mergeKsorted(vector<vector<int>> &arr)
{
    priority_queue<pair, vector<pair>, greater<pair>> pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});

    while (pq.size() != 0)
    {
        pair p = pq.top();
        pq.pop();
        cout << p.first << " ";

        int arIdx = p.second.first;
        int eleIdx = p.second.second;

        if (eleIdx + 1 < arr[arIdx].size())
            pq.push({arr[arIdx][eleIdx + 1], {arIdx, eleIdx + 1}});
    }
}

//Median.============================================================



void questionSet2()
{
    vector<vector<int>> arr{{5, 15, 25}, {11, 14, 22}, {2, 7, 17}, {9, 12, 18}};
    mergeKsorted(arr);
}

//============================================================

void solve()
{
    // pqfunctions();
    // questionSet1();
    questionSet2();
}

int main(int args, char **argc)
{
    solve();
    return 1;
}