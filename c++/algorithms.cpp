#include <iostream>
using namespace std;

// Bubble sort
void bubbleSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion sort
void insertionSort(int arr[], int size) {
    for (int i=1; i<size; i++) {
        while (arr[i-1] > arr[i] && i > 0) {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i-1] = temp;
            i--;
        }
    }
}

// Selection sort
void selectionSort(int arr[], int size) {
    for (int i=0; i<size-1; i++) {
        int min_index = i;
        for (int j=i+1; j<size; j++) {
            if (arr[j]<arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i]=temp;
    }
}

int main() {
    int size = 10, arr[size] = {4, 5, 6, 9, 7, 1, 2, 10, 3, 8};
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, size);
    cout << "bubble sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, size);
    cout << "insertion sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    selectionSort(arr, size);
    cout << "selection sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
