/*
1. create two array of 5 real numpers. Input their values with the keyboard and 
then print them on the screen. (2 points)
2. Sort the first array using the bubble sort. (2 points)
3. Compute the average values of both arrays and print them on the screen. (2 points)
4. Input a further element with the keyboard and verify if it is bigger than
the first average and less than the second average. (1 point)
5. If the above condition is verified, insert it in the first sorted array the
element in it's correct position, that is, the position that preserves the order
of array elements. (2 points)
6. Structure the program with appropriate subprograms. (1 point)
*/

#include <iostream>
using namespace std;

void createArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cin>>arr[i]; //i=0, i=1, i=2....
    }
}

void print(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// 2 1 3 4 5
void bubbleSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // swap
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 1 2 3 4 5
void average(int arr[], int size, double& av) {
    double sum=0;
    for(int i=0; i<size; i++) { // i=0, i=1, i=2, i=3, i=4
        sum = sum + arr[i];
    }
    av = sum/size;
}

// 1 2 3 4 5 , input = 6, size = 5, size++, size = 6
void verify(int arr[], int& size, int input, double av1, double av2) {
    if(input > av1 && input < av2) {
        cout<<"The given condition satisfies!"<<endl;
        size++;
        arr[size-1] = input;
    }
    else {
        cout<<"The given condition doesn't satisfy!"<<endl;
    }
}

int main() {
    int size = 5, input, arr1[size], arr2[size];
    double av1, av2;

    cout<<"Enter first array's element: ";
    createArray(arr1, size);

    cout<<"Enter second array's element: ";
    createArray(arr2, size);

    cout<<"first array: ";
    print(arr1, size);

    cout<<"second array: ";
    print(arr2, size);

    bubbleSort(arr1, size);
    cout<<"first array after sorting: ";
    print(arr1, size);

    average(arr1, size, av1);
    average(arr2, size, av2);
    cout<<"The average of array one: "<<av1<<endl;
    cout<<"The average of array two: "<<av2<<endl;

    cout<<"Input a further element: ";
    cin>>input;
    verify(arr1, size, input, av1, av2);

    print(arr1, size);

    return 0;
}
