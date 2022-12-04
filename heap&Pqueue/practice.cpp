#include <bits/stdc++.h>
using namespace std;

void maxHeapFi(int arr[], int n, int current)
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
        maxHeapFi(arr, n, largest);
    }
}
void minHeapFi(int arr[], int n, int current)
{
    int largest = current;
    int leftChild = (current * 2) + 1;
    int rightChild = (current * 2) + 2;

    if (leftChild < n && arr[leftChild] < arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild < n && arr[rightChild] < arr[largest])
    {
        largest = rightChild;
    }

    if (largest != current)
    {
        swap(arr[current], arr[largest]);
        minHeapFi(arr, n, largest);
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
        maxHeapFi(arr, i, 0);
    }
}

void DeleteRoot(int arr[], int &n)
{
    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n -= 1;
    minHeapFi(arr, n, 0);
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

    // printArray(array, n);
    // HeapIfy
    // int noneLeafStart = (n / 2) - 1;
    // for (int i = noneLeafStart; i >= 0; i--)
    // {
    //     minHeapFi(array, n, i);
    // }

    for (int i = n; i > 0; i--)
    {
        DeleteRoot(array, n);
        printArray(array, n);
        cout << endl;
    }

    // cout << "heap sort " << endl;
    // heapSort(array, n);
    // printArray(array, n);
    return 0;
}

/*

6
1 2 3 4 5 9

7
-10 2 5 4 7 8 1

9
2 10 1 5 4 8 3 8 7

9
2 4 1 10 5 7 3 12 8
*/