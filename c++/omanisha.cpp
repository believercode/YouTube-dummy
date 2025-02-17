#include <iostream>

using namespace std;

void inputArray(int arr[], int size) {
    cout << "Enter " << size << " integer values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int removeGreaterThanX(int arr[], int size, int x) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= x) {
            arr[newSize++] = arr[i];
        }
    }
    return newSize;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double computeAverage(int arr[], int size) {
    if (size == 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int insertSorted(int arr[], int size, double value) {
    int i;
    for (i = size - 1; (i >= 0 && arr[i] > value); i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = static_cast<int>(value);
    return size + 1;
}

int main() {
    int arr[11];
    int size = 10;
    inputArray(arr, size);
    printArray(arr, size);

    int x;
    cout << "Enter a number x: ";
    cin >> x;
    size = removeGreaterThanX(arr, size, x);
    printArray(arr, size);

    bubbleSort(arr, size);
    printArray(arr, size);

    double avg = computeAverage(arr, size);
    cout << "Average: " << avg << endl;
    size = insertSorted(arr, size, avg);
    printArray(arr, size);

    return 0;
}
