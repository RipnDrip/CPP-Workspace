#include <iostream>
#include <algorithm>
#include <time.h>

#include "Sorting.h"





int Sorting::selectionSort(int array[], int n) {
   int count, i, j, temp;
   count = 0;
    for (j = 0; j < n; ++j) {
        for (i = j + 1; i < n; ++i)
        {
            if (array[j] > array[i])
            {
                count++;
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

   
    return count;
}

void Sorting::merge(int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            count++;
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

int Sorting::mergeSort(int array[], int i, int j)
{
    int m;

    if (i < j)
    {
        m = i + (j - i) / 2;
        mergeSort(array, i, m);
        mergeSort(array, m + 1, j);
        merge(array, i, m, j);
    }
    return count;
}

void Sorting::heaper(int array[], int n, int i, int &count)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && array[l] > array[largest])
    {
        largest = l;
        count++;
    }

    if (r < n && array[r] > array[largest])
    {
        largest = r;
        count++;
    }

    if (largest != i)
    {
        std::swap(array[i], array[largest]);

        heaper(array, n, largest, count);
    }
}

int Sorting::heapSort(int array[], int n)
{
    int count = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
        heaper(array, n, i, count);

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(array[0], array[i]);
        heaper(array, i, 0, count);
    }
    return count;
}

int Sorting::partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            compares++;
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return (i + 1);
}

int Sorting::quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
    return compares;
}

int Sorting::rPartition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            rcount++;
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return (i + 1);
}

int Sorting::rPivot(int array[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    std::swap(array[random], array[high]);

    return rPartition(array, low, high);
}

int Sorting::randomQuickSort(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            rcount++;
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return (i + 1);
}
