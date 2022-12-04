#include <bits/stdc++.h>
using namespace std;

void heapFfy(int arr[], int n, int current)
{
    int largest = current;
    int leftChild = (current * 2) + 1;
    int rightChild = (current * 2) + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != current)
    {
        swap(arr[current], arr[largest]);
        heapFfy(arr, n, largest);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int arr[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapFfy(arr, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    printArray(array, n);
    // HeapIfy
    int noneLeafStart = (n / 2) - 1;
    for (int i = noneLeafStart; i >= 0; i--)
    {
        heapFfy(array, n, i);
    }
    printArray(array, n);

    // cout << "heap sort " << endl;
    // heapSort(array, n);
    // printArray(array, n);
    return 0;
}

/*
9
2 10 1 5 4 8 3 8 7

9
2 4 1 10 5 7 3 12 8
*/