/*
1. Create an array of 10 integer numbers, input its value with the keyboard,
   and then print it on the screen. (2 points)
2. Input a further element x from the keyboard and verify if there are elements 
   in the array bigger than x. If there are, delete all of them from the array. (3 points)
3. Sort the array in ascending order using bubble sort algorithm. (2 points)
4. Compute the average value of the modified array and insert it in the sorted 
   array while preserving the order. (2 points)
5. Structure the program with appropriate subprograms. (1 point)
*/

#include <iostream>
using namespace std;

void createArray(int arr[], int size) {
    cout<<"Enter "<<size<<" integers: "<<endl;
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
}

void print(int arr[], int size) {
    for(int i=0;i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int deleteElements(int arr[], int size, int x) {
    int newSize = 0;
    for(int i=0; i<size; i++) {
        if(arr[i]<=x) {
            arr[newSize++] = arr[i];
        }
    }
    return newSize;
}

void bubbleSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1-i; j++) {
            if(arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertAverage(int arr[], int size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum += arr[i];
    }
    int average = sum/size;
    cout<<"The average value: "<<average<<endl;
    arr[size] = average;
}

int main() {
    int arr[11], size=10, x;
    createArray(arr, size);
    cout<<"Array: ";
    print(arr, size);
    
    cout<<"Enter x: ";
    cin>>x;

    size = deleteElements(arr, size, x);
    cout<<"Modified array: ";
    print(arr, size);
    
    bubbleSort(arr, size);
    cout<<"Sorted array: ";
    print(arr, size);

    insertAverage(arr, size);
    cout<<"Final array: ";
    print(arr, size+1);

    return 0;
}
