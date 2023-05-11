/*Tas1. Create a function that allows you to add a block
elements at the end of the array.*/

#include <iostream>

using namespace std;

void addBlockToEnd(int*& arr, int size);
void printArray(int*& arr, int size);
void printNewArray(int*& arr, int size);

int main() {

    int size = 3;
    int* arr = new int[size] {3, 3, 3};

    printArray(arr, size); // function to display original array
    addBlockToEnd(arr, size); // function to add new elements
    printNewArray(arr,  size);// function to display new array

    cout << endl;

    delete[] arr; // free memory used by final array
    return 0;
}
void printArray(int*& arr, int size) {

    for (int i = 0; i < size; i++) {

        cout << *(arr + i) << " "; // print orginal array
    }
}
void printNewArray(int*& arr, int size) {

    cout << "New array:\n";

    for (int i = 0; i < 2 * size; i++) {

        cout << *(arr + i) << " "; // print new array
    }

}
void addBlockToEnd(int*& arr, int size) {

    int* block = new int[size]; // dynamically allocate memory for the block
    cout << "\nEnter block of integers to add:\n";

    for (int i = 0; i < size; i++) {

        cin >> *(block + i); // user input new elements
    }

    int* newarr = new int[2 * size]; // dynamically allocate memory for the new array
    for (int i = 0; i < size; i++) {

        *(newarr + i) = *(arr + i); // copy elements from original array to new array
    }
    for (int i = 0; i < size; i++) {

        *(newarr + size + i) = *(block + i); // copy elements from block to new array
    }

    delete[] arr; // free memory used by original array
    delete[] block; // free memory used by block
    arr = newarr; // update pointer to point to new array
}
