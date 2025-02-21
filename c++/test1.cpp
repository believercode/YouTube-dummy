/*
Write a C++ program that:
1.creates two arrays of 10 random integers in the range of values from 1 to 20
(points: 2)
2.compute the difference of each element at the same position in the two arrays
mentioned above and insert it a new vector "diff" (points: 2)
3.sorts the second array and the "diff" arrays
(points: 2)
4.starting from the array sorted at point 3 merge their values in a new sorted
array (points: 2)
5. Structure the program with appropriate subprograms. (points: 2)
*/
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void createArr(int arr[], int size) {
    for(int i=0; i<size; i++) {
        arr[i] = (rand() % 20) + 1;
    }
}

void print(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void difference(vector<int>& diff, int arr1[], int arr2[], int size) {
    for(int i=0; i<size; i++) {
        diff.push_back(arr1[i]-arr2[i]);
    }
}

void sortArr(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1-i; j++) {
            if(arr[j]>arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortVec(vector<int>& diff, int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1-i; j++) {
            if(diff[j]>diff[j+1]) {
                int temp = diff[j+1];
                diff[j+1] = diff[j];
                diff[j] = temp;
            }
        }
    }
}

void merge(int arr[], vector<int>& diff, int size) {
    int i, j;
    for(i=0; i<size; i++) {
        
    }
}

int main() {
    int size=5, arr1[size], arr2[size];
    vector<int> diff;
    srand(time(0));

    createArr(arr1, size);
    createArr(arr2, size);
    print(arr1, size);
    print(arr2, size);

    difference(diff, arr1, arr2, size);
    for (int i = 0; i < size; i++)
    {
        cout<<diff[i]<<" ";
    }
    cout<<endl;
    
    sortArr(arr1, size);
    sortVec(diff, size);
    print(arr1, size);
    for (int i = 0; i < size; i++)
    {
        cout<<diff[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}
