#include <iostream>
#include <fstream>
#include <random>

#include "Sorting.h"
#include "Sorting.cpp"

using namespace std;
int main(int argc, char *argv[])
{
    int n, size;     
    cout << "Enter size of the array" << endl;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % INT_MAX);
    }

    Sorting *sorter = new Sorting();
    n = sizeof(array) / sizeof(array[0]);
    char opt;
    cout << "Sort using: \n";
    cout << "Selection-Sort (s)\n";
    cout << "Merge-Sort (m)\n";
    cout << "Heap-Sort (h)\n";
    cout << "Quick-Sort-fp (q).\n";
    cout << "Quick-Sort-rp (r) \n";

    cout << "Enter the algorithm" << endl;
    cin >> opt;

    int count = 0;
    switch (opt)
    {
    case 's':
        count = sorter->selectionSort(array, n);
        break;
    case 'm':
        count = sorter->mergeSort(array, 0, n - 1);
        break;
    case 'q':
        count = sorter->quickSort(array, 0, n - 1);
        break;
    case 'r':
        count = sorter->randomQuickSort(array, 0, n - 1);
        break;
    case 'h':
        count = sorter->heapSort(array, n);
        break;
    default:
        cout << "Invalid option";
    }

    cout << "Sorted array is \n";
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << "\n";
    cout << "Number of comparisons: " << count;
    //return 0;
}
