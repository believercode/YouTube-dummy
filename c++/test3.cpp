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
#include <fstream>
using namespace std;

void createArr(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
}

void print(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int verify(int arr[], int size, int& input) {
    for(int i=0; i<size; i++) {
        if(input == arr[i]) {
            return i;
        }
    }
    return -1;
}

// 1 2 3 4 5
void deleteElement(int arr[], int& size, int pos) {
    for(int i=pos; i<size-1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
}

void selectionSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        int min_index = i;
        for(int j=i+1; j<size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void saveToFile(const int arr[], int size, const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            file << arr[i] << " ";
        }
        cout<<"File saved to "<<filename<<endl;
        file.close();
    } else {
        cerr << "Error opening file!" << endl;
    }
}

int main() {
    int size = 10, arr[size+1], input;

    cout<<"Enter elements: "<<endl;
    createArr(arr, size);
    cout<<"Array: ";
    print(arr, size);

    cout<<"Enter a farther element: ";
    cin>>input;
    int pos = verify(arr, size, input);

    if(pos!=-1) {
        deleteElement(arr, size, pos);
    }
    else {
        arr[size] = input;
    }
    print(arr, size);

    selectionSort(arr, size);
    print(arr, size);

    saveToFile(arr, size, "store.txt");

    return 0;
}
