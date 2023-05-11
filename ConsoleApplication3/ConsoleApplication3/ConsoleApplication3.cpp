/*Task3. Create a function that allows you to delete from an array
elements from n to m. After
elements are deleted, the array must be truncated.*/

#include <iostream>

using namespace std;

void fillArray(int* arr, int& size);
void printArray(int* arr, int& size);
void deleteElements(int* arr, int& size, int* n, int* m);

int main() {

    srand(time(NULL));

    // Get the size of the array from the user
    int size, n, m;
    cout << "Enter size: ";
    cin >> size;

    // Allocate memory for the array
    int* arr = new int[size];

    // Fill the array with random numbers and print it
    fillArray(arr, size);
    printArray(arr, size);

    // Get the range of elements to be deleted from the user
    cout << "\nTo delete elements in range from n to m, enter index n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    // Delete the elements and print the modified array
    deleteElements(arr, size, &n, &m);
    printArray(arr, size);

    // Free the memory allocated for the array
    delete[] arr;

    return 0;
}

void fillArray(int* arr, int& size) {

    // Fill the array with random numbers between 0 and 99
    for (int i = 0; i < size; i++) {

        *(arr + i) = rand() % 100;
    }
}

void printArray(int* arr, int& size) {

    // Print the elements of the array
    for (int i = 0; i < size; i++) {

        cout << *(arr + i) << " ";
    }
}

void deleteElements(int* arr, int& size, int* n, int* m) {

    // Calculate the size of the range to be deleted
    int new_size = *m - *n + 1;

    // Shift the elements after the range to the left
    for (int i = *n; i <= *m; i++) {

        *(arr + i) = *(arr + i + new_size);
    }

    // Reduce the size of the array
    size -= new_size;
}
