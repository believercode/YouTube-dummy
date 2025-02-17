/*
Write a C++ program that:
1. Create an array of 10 integer numbers, input its value with the keyboard,
   and then print it on the screen. (2 points)
2. Input a further element from the keyboard and verify if it is present in
   the array. If it is present, print its position on the screen and store
   its position in the variable pos
   (note that pos initial value was -1). (1 point)
3. If pos is equal to -1, insert the element described in step 2 at the end of
   the array;
   otherwise, delete from the array the element at position pos. (3 points)
4. Sort the array using the selection sort algorithm. (2 points)
5. Open a file and store the array in the file. (1 point)
6. Structure the program with appropriate subprograms. (1 point)
*/

#include <iostream>
using namespace std;

void createArray(int arr[], int size) {
    int inp;
    cout<<"Enter "<<size<<" integers: "<<endl;
    for(int i=0;i<size;i++) {
        cin>>inp;
        arr[i] = inp;
    }
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[11], size = 10;
    createArray(arr, size);

    cout<<"Array: ";
    printArray(arr, size);


    return 0;
}
 