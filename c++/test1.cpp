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
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void createArrays(vector<int>& arr1, vector<int>& arr2) {
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        arr1.push_back(rand() % 20 + 1);
        arr2.push_back(rand() % 20 + 1);
    }
}

void computeDiff(vector<int>& arr1, vector<int>& arr2, vector<int>& diff) {
    for (int i = 0; i < 10; i++) {
        diff.push_back(arr1[i] - arr2[i]);
    }
}

void sortArrays(vector<int>& arr1, vector<int>& arr2, vector<int>& diff) {
    sort(arr2.begin(), arr2.end());
    sort(diff.begin(), diff.end());
}

void mergeArrays(vector<int>& arr1, vector<int>& arr2, vector<int>& diff, vector<int>& merged) {
    int i = 0, j = 0, k = 0;
    while (i < 10 && j < 10 && k < 10) {
        if (arr2[j] < diff[k]) {
            merged.push_back(arr2[j]);
            j++;
        }
        else if (arr2[j] > diff[k]) {
            merged.push_back(diff[k]);
            k++;
        }
        else {
            merged.push_back(arr2[j]);
            j++;
            k++;
        }
    }
    while (i < 10 && k < 10) {
        merged.push_back(diff[k]);
        k++;
    }
    while (j < 10 && i < 10) {
        merged.push_back(arr2[j]);
        j++;
    }
    while (i < 10) {
        merged.push_back(arr1[i]);
        i++;
    }
    
}

int main() {
    vector<int> arr1, arr2, diff, merged;
    createArrays(arr1, arr2);
    computeDiff(arr1, arr2, diff);
    sortArrays(arr1, arr2, diff);
    mergeArrays(arr1, arr2, diff, merged);
    for (int i = 0; i < 10; i++) {
        cout << merged[i] << " ";
    }
    return 0;
}
