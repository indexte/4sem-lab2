#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H
#include <iostream>

using std::swap;

template<class T>
void insertion_sort(T arr[], int n){
    T key;
    for (int j, i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

template<class T>
int partition(T arr[], int low, int high){
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template<class T>
void quick_sort(T arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

template<class T>
void heapify(T arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template<class T>
void heap_sort(T arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
          heapify(arr, i, 0);
    }
}

#endif // SORT_ALGORITHMS_H
