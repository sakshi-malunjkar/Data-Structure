/*
Name : Prachi Mehetre
Class : SE B2
Roll no.: 47
PROBLEM STATEMENT :
Sorting: Write a C++ menu driven program to store the percentage of 
marks obtained by the students in an array. Write function for sorting array 
of floating point numbers in ascending order using 
1. Selection Sort 
2. Bubble sort 
3. Insertion sort 
4. Shell Sort
5. Quick sort 
6. Radix sort 
7. Display top five scores 
Implement 4 methods of sorting. Provide choice to user to take input from 
user or using random numbers.
Use Standard Template Library (STL) sort function for above data.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

const int ARRAY_SIZE = 10;

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Input marks manually\n";
    cout << "2. Generate random marks\n";
    cout << "3. Sort using Selection Sort\n";
    cout << "4. Sort using Bubble Sort\n";
    cout << "5. Sort using Insertion Sort\n";
    cout << "6. Sort using Shell Sort\n";
    cout << "7. Sort using Quick Sort\n";
    cout << "8. Sort using Radix Sort\n";
    cout << "9. Sort using STL Sort\n";
    cout << "10. Display top five scores\n";
    cout << "11. Exit\n";
}

void inputMarks(float marks[]) {
    cout << "Enter marks for " << ARRAY_SIZE << " students:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }
}

void generateRandomMarks(float marks[]) {
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        marks[i] = rand() % 101; // Generate random percentage marks between 0 and 100
    }
    cout << "Random marks generated.\n";
}

void displayTopFiveScores(float marks[])
{
    sort(marks, marks + ARRAY_SIZE, greater<float>());
    cout << "Top five scores:\n";
    for (int i = 0; i < min(5, ARRAY_SIZE); ++i) {
        cout << "Rank " << i + 1 << ": " << marks[i] << "%\n";
    }
}

// Implement sorting algorithms
void selectionSort(float marks[]) {
    for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < ARRAY_SIZE; ++j) {
            if (marks[j] < marks[minIndex]) {
                minIndex = j;
            }
        }
        swap(marks[i], marks[minIndex]);
    }
}

void bubbleSort(float marks[]) {
    for (int i = 0; i < ARRAY_SIZE - 1; ++i) 
	{
        for (int j = 0; j < ARRAY_SIZE - i - 1; ++j) 
		{
            if (marks[j] > marks[j + 1]) 
			{
                swap(marks[j], marks[j + 1]);
            }
        }
    }
}

void insertionSort(float marks[]) {
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        float key = marks[i];
        int j = i - 1;

        while (j >= 0 && marks[j] > key) {
            marks[j + 1] = marks[j];
            j = j - 1;
        }
        marks[j + 1] = key;
    }
}

void shellSort(float marks[]) {
    for (int gap = ARRAY_SIZE / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < ARRAY_SIZE; ++i) {
            float temp = marks[i];
            int j;
            for (j = i; j >= gap && marks[j - gap] > temp; j -= gap) {
                marks[j] = marks[j - gap];
            }
            marks[j] = temp;
        }
    }
}

void quickSort(float marks[], int low, int high) {
    if (low < high) {
        int pivot = marks[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; ++j) {
            if (marks[j] > pivot) {
                ++i;
                swap(marks[i], marks[j]);
            }
        }

        swap(marks[i + 1], marks[high]);

        int partitionIndex = i + 1;

        quickSort(marks, low, partitionIndex - 1);
        quickSort(marks, partitionIndex + 1, high);
    }
}

void radixSort(float marks[]) {
    int maxExp = 1;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        while (marks[i] > pow(10, maxExp)) {
            ++maxExp;
        }
    }

    for (int exp = 1; maxExp / exp > 0; exp *= 10) {
        int output[ARRAY_SIZE];
        int count[10] = {0};

        for (int i = 0; i < ARRAY_SIZE; ++i) {
            count[(int)(marks[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = ARRAY_SIZE - 1; i >= 0; --i) {
            output[count[(int)(marks[i] / exp) % 10] - 1] = marks[i];
            count[(int)(marks[i] / exp) % 10]--;
        }

        for (int i = 0; i < ARRAY_SIZE; ++i) {
            marks[i] = output[i];
        }
    }
}

int main() {
    float marks[ARRAY_SIZE];
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputMarks(marks);
                break;

            case 2:
                generateRandomMarks(marks);
                break;

            case 3:
                selectionSort(marks);
                cout << "Array sorted using Selection Sort.\n";
                break;

            case 4:
                bubbleSort(marks);
                cout << "Array sorted using Bubble Sort.\n";
                break;

            case 5:
                insertionSort(marks);
                cout << "Array sorted using Insertion Sort.\n";
                break;

            case 6:
                shellSort(marks);
                cout << "Array sorted using Shell Sort.\n";
                break;

            case 7:
                quickSort(marks, 0, ARRAY_SIZE - 1);
                cout << "Array sorted using Quick Sort.\n";
                break;

            case 8:
                radixSort(marks);
                cout << "Array sorted using Radix Sort.\n";
                break;

            case 9:
                sort(marks, marks + ARRAY_SIZE);
                cout << "Array sorted using STL Sort.\n";
                break;

            case 10:
                displayTopFiveScores(marks);
                break;

            case 11:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 11);

    return 0;
}
