/*Task4
The array is given: А[M] (M is entered from the keyboard).
The user enters data into the array, as well as by
using the menu decides what to delete from
array to choose from:
● Paired elements
● Odd element
● Maximum element
● Minimal element
● Elements greater than the median of the array
● Elements smaller than the median of the array*/

#include <iostream>
#include <algorithm>
using namespace std;

void fillArray(int* A, int M);
void printArray(int* A, int M);
void deletePairedElements(int* A, int& M);
int* deleteOddElements(int* A, int& M);
int* deleteMaxElement(int* A, int& M);
int* deleteMinElement(int* A, int& M);
double calculateMedian(int* A, int M);
int* deleteElementsGreaterThanMedian(int* A, int& M);
int* deleteElementsSmallerThanMedian(int* A, int& M);

int main()
{
    // initialize array
    int M;
    cout << "Enter the size of the array: ";
    cin >> M;
    int* A = new int[M];

    cout << endl;

    // fill and display array
    cout << "Enter values for array: ";
    fillArray(A, M);
    printArray(A, M);

    cout << endl;      

    // menu
    int menu_choice = 0;
    cout << "\nChoose what to delete from array: " << endl;
    cout << "1. Paired elements.\n2. Odd elements.\n3. Maximum elements.\n4. Minimal elements.";
    cout << "\n5. Elements greater than the median of the array.\n6. Elements smaller than the median of the array.\n";
    cin >> menu_choice;

        // Function to delete Paired elements
        if (menu_choice == 1) {

            deletePairedElements(A, M);
            printArray(A, M);
        }
        // Function to delete Odd elements
        if (menu_choice == 2) {

            A = deleteOddElements(A, M);

            // Displaying the modified array
            cout << "Modified array after deleting odd elements:\n";
            for (int i = 0; i < M; i++) {

                cout << *(A + i) << " ";
            }
            cout << endl;
        }
        // Function to delete Maximum elements
        if (menu_choice == 3) {

            A = deleteMaxElement(A, M);

            // Displaying the modified array 
            cout << "Modified array after deleting the maximum element:\n";
            for (int i = 0; i < M; i++) {

                cout << *(A + i) << " ";
            }
            cout << endl;
        }
        // Function to delete Minimal elements
        if (menu_choice == 4) {

            A = deleteMinElement(A, M);

            // Displaying the modified array
            cout << "Modified array after deleting the minimum elements:\n";
            for (int i = 0; i < M; i++) {

                cout << *(A + i) << " ";
            }
            cout << endl;
        }
        // Function to delete elements greater than the median
        if (menu_choice == 5) {

            // Deleting elements greater than the median from the array
            A = deleteElementsGreaterThanMedian(A, M);

            // Displaying the modified array
            cout << "Modified array after deleting elements greater than the median:\n";
            for (int i = 0; i < M; i++) {

                cout << *(A + i) << " ";
            }
            cout << endl;
        }
        // Function to delete elements smaller than the median
        if (menu_choice == 6) {

            // Deleting elements smaller than the median from the array
            A = deleteElementsSmallerThanMedian(A, M);

            // Displaying the modified array
            cout << "Modified array after deleting elements smaller than the median:\n";
            for (int i = 0; i < M; i++) {
                cout << *(A + i) << " ";
            }
            cout << endl;
        }


    delete[] A; // Free the allocated memory

    return 0;
}

void deletePairedElements(int* A, int& M) {

    int i = 0;
    while (i < M) {

        if (i + 1 < M && A[i] == A[i + 1]) {
            // Found a pair of consecutive elements that are the same

            // Shift elements to the left by two positions, effectively deleting the pair
            for (int j = i; j < M - 2; j++) {

                A[j] = A[j + 2];
            }
            M -= 2;// Update the size of the array
        }
        else {

            i++;// Move to the next element
        }
    }
}
int* deleteOddElements(int* A, int& M) {
    int newSize = 0; // New size of the array after deleting odd elements

    // Counting the number of even elements
    for (int i = 0; i < M; i++) {

        if (*(A + i) % 2 == 0) {

            newSize++;
        }
    }

    // Creating a new array to hold even elements
    int* newArr = new int[newSize];
    int index = 0;

    // Copying even elements to the new array
    for (int i = 0; i < M; i++) {

        if (*(A + i) % 2 == 0) {

            *(newArr + index) = *(A + i);
            index++;
        }
    }

    // Updating the size of the array
    M = newSize;

    // Deleting the old array
    delete[] A;

    return newArr;
}
int* deleteMaxElement(int* A, int& M) {

    if (M == 0) {

        return A; // Empty array, nothing to delete
    }

    // Finding the maximum element in the array
    int maxElement = *A;
    for (int i = 1; i < M; i++) {
        if (*(A + i) > maxElement) {
            maxElement = *(A + i);
        }
    }

    // Counting the number of elements that are not the maximum
    int newSize = 0;
    for (int i = 0; i < M; i++) {
        if (*(A + i) != maxElement) {
            newSize++;
        }
    }

    // Creating a new array to hold the elements that are not the maximum
    int* newArr = new int[newSize];
    int index = 0;

    // Copying the elements that are not the maximum to the new array
    for (int i = 0; i < M; i++) {

        if (*(A + i) != maxElement) {

            *(newArr + index) = *(A + i);
            index++;
        }
    }

    // Updating the size of the array
    M = newSize;

    // Deleting the old array
    delete[] A;

    return newArr;
}
int* deleteMinElement(int* A, int& M) {
    if (M == 0) {

        return A; // Empty array, nothing to delete
    }

    // Finding the minimum element in the array
    int minElement = *A;
    for (int i = 1; i < M; i++) {

        if (*(A + i) < minElement) {

            minElement = *(A + i);
        }
    }

    // Counting the number of elements that are not the minimum
    int newSize = 0;

    for (int i = 0; i < M; i++) {

        if (*(A + i) != minElement) {

            newSize++;
        }
    }

    // Creating a new array to hold the elements that are not the minimum
    int* newArr = new int[newSize];
    int index = 0;

    // Copying the elements that are not the minimum to the new array
    for (int i = 0; i < M; i++) {

        if (*(A + i) != minElement) {

            *(newArr + index) = *(A + i);
            index++;
        }
    }

    // Updating the size of the array
    M = newSize;

    // Deleting the old array
    delete[] A;

    return newArr;
}
// Function to calculate the median of the array
double calculateMedian(int* A, int M) {

    sort(A, A + M); // Sorting the array

    if (M % 2 == 0) {

        // Array size is even, average of middle elements is the median
        return (double)(A[M / 2 - 1] + A[M / 2]) / 2;
    }
    else {

        // Array size is odd, middle element is the median
        return (double)(A[M / 2]);
    }
}

// Function to delete elements greater than the median from the array
int* deleteElementsGreaterThanMedian(int* A, int& M) {

    if (M == 0) {

        return A; // Empty array, nothing to delete
    }

    double median = calculateMedian(A, M);

    // Counting the number of elements that are not greater than the median
    int newSize = 0;
    for (int i = 0; i < M; i++) {

        if (*(A + i) <= median) {
            newSize++;
        }
    }

    // Creating a new array to hold the elements that are not greater than the median
    int* newArr = new int[newSize];
    int index = 0;

    // Copying the elements that are not greater than the median to the new array
    for (int i = 0; i < M; i++) {

        if (*(A + i) <= median) {

            *(newArr + index) = *(A + i);
            index++;
        }
    }

    // Updating the size of the array
    M = newSize;

    // Deleting the old array
    delete[] A;

    return newArr;
}
int* deleteElementsSmallerThanMedian(int* A, int& M) {
    if (M == 0) {
        return A; // Empty array, nothing to delete
    }

    double median = calculateMedian(A, M);

    // Counting the number of elements that are not smaller than the median
    int newSize = 0;
    for (int i = 0; i < M; i++) {
        if (*(A + i) >= median) {
            newSize++;
        }
    }

    // Creating a new array to hold the elements that are not smaller than the median
    int* newArr = new int[newSize];
    int index = 0;

    // Copying the elements that are not smaller than the median to the new array
    for (int i = 0; i < M; i++) {
        if (*(A + i) >= median) {
            *(newArr + index) = *(A + i);
            index++;
        }
    }

    // Updating the size of the array
    M = newSize;

    // Deleting the old array
    delete[] A;

    return newArr;
}

void printArray(int* A, int M) {

    cout << endl;
    for (int i = 0; i < M; i++) {

        cout << *(A + i) << " ";
    }
    cout << endl;
}

void fillArray(int* A, int M) {

    for (int i = 0; i < M; i++) {

        cin >> *(A + i);
    }
}
