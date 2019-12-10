#include <iostream>
using namespace std;

class kstacks
{
private:
    int *dataArray;
    int *pointerArray;

    int *stackHeadArray;
    int *stackCapacity;

    int freeHeadIndex;
    int capacity;

public:
    kstacks(int capacity, int noOfStacks)
    {
        this->dataArray = new int[capacity];

        this->pointerArray = new int[capacity];
        this->stackHeadArray = new int[noOfStacks];

        this->stackCapacity = new int[noOfStacks];

        this->freeHeadIndex = 0;
        this->capacity = capacity;

        for (int i = 0; i < this->capacity; i++)
        {
            this->dataArray[i] = 0;
            this->pointerArray[i] = i + 1;
        }
        this->pointerArray[this->capacity - 1] = -1;

        for (int i = 0; i < noOfStacks; i++)
        {
            this->stackHeadArray[i] = -1;
            this->stackCapacity[i] = 0;
        }
    }

    bool isEmpty(int stackNo)
    {
        return this->stackHeadArray[stackNo] == -1;
    }

    int isFull()
    {
        return this->freeHeadIndex == -1;
    }

    void push(int data, int stackNo)
    {
        if (this->freeHeadIndex == -1)
        {
            cout << "IndexOutOfBoundExcetion" << endl;
            return;
        }

        int tempFree = this->freeHeadIndex;                            //new Free spot index.
        this->freeHeadIndex = this->pointerArray[this->freeHeadIndex]; //new freeHeadIndex.

        this->pointerArray[tempFree] = this->stackHeadArray[stackNo];
        this->stackHeadArray[stackNo] = tempFree;

        this->dataArray[tempFree] = data;
        this->stackCapacity[stackNo]++;
    }

    int pop(int stackNo)
    {
        if (this->stackHeadArray[stackNo] == -1)
        {
            cout << "NullPointException" << endl;
            return -1;
        }

        int newAvailableSpot = this->stackHeadArray[stackNo];
        int rv = this->dataArray[newAvailableSpot];

        this->stackHeadArray[stackNo] = this->pointerArray[newAvailableSpot];
        this->pointerArray[newAvailableSpot] = this->freeHeadIndex;

        this->freeHeadIndex = newAvailableSpot;
        this->stackCapacity[stackNo]--;

        return rv;
    }

    int top(int stackNo)
    {

        if (this->stackHeadArray[stackNo] == -1)
        {
            cout << "NullPointException" << endl;
            return -1;
        }
    }
};