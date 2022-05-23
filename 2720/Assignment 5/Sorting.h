#ifndef ASSN05_SORTING_H
#define ASSN05_SORTING_H

class Sorting
{
public:
    int MinIndex( int array[], int start, int end);
    int selectionSort(int array[], int n);
    void merge(int arr[], int l, int m, int r);
    int mergeSort(int arr[], int i, int);
    void heaper(int arr[], int n, int i, int &count);
    int heapSort(int arr[], int n);
    int partition(int arr[], int low, int high);
    int quickSort(int arr[], int low, int high);
    int rPartition(int arr[], int low, int high);
    int rPivot(int arr[], int low, int high);
    int randomQuickSort(int arr[], int low, int high);

private:
    int count;
    int rcount;
    int compares;
};
#endif