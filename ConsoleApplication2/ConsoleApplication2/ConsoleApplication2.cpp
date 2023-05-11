/*Task2. Create a function that allows you to insert a block
elements, starting from an arbitrary index of the array*/

#include <iostream>

using namespace std;

void insertBlockAtIndex(int*& arr, int size, int* block, int blockSize, int index);
void newBlock(int* block, int size, int BlockSize);
void printArray(int* arr, int size);
void printNewArray(int* arr, int size, int blockSize);

int main() {

    int size = 3; // size of initial array
    int* arr = new int[size] {3, 3, 3}; // dynamically allocate memory for initial array
    printArray(arr, size); // function call to print new array

    int blockSize = size; // size of block array
    int* block = new int[blockSize]; // dynamically allocate memory for block array
    cout << "Enter block of integers to add:\n";
    newBlock(block, size, blockSize); // function call to input values for block array

    int index; // index to insert block
    cout << "Enter index: ";
    cin >> index; // input index
    insertBlockAtIndex(arr, size, block, blockSize, index); // function call to insert block at specified index

    cout << "New array:\n";
    printNewArray(arr, size, blockSize); // function call to printp;l array

    delete[] arr; // free memory used by final array
    delete[] block; // free memory used by block
    return 0;
}
void insertBlockAtIndex(int*& arr, int size, int* block, int blockSize, int index) {

    int* newarr = new int[size + blockSize]; // dynamically allocate memory for the new array

    for (int i = 0; i < index; i++) {

        *(newarr + i) = *(arr + i); // copy elements from original array to new array before index
    }
    for (int i = 0; i < blockSize; i++) {

        *(newarr + index + i) = *(block + i); // copy elements from block to new array at index
    }
    for (int i = index; i < size; i++) {

        *(newarr + blockSize + i) = *(arr + i); // copy elements from original array to new array after index
    }

    delete[] arr; // free memory used by original array
    arr = newarr; // update pointer to point to new array
}
void newBlock(int* block, int size, int blockSize) {

    for (int i = 0; i < blockSize; i++) {

        cin >> *(block + i); // new elements
    }
}
void printArray(int* arr, int size) {

    for (int i = 0; i < size; i++) {

        cout << *(arr + i) << " "; // print original array
    }
    cout << endl;
}
void printNewArray(int* arr, int size, int blockSize) {

    for (int i = 0; i < size + blockSize; i++) {

        cout << *(arr + i) << " "; // print elements of the final array
    }
    cout << endl;
}