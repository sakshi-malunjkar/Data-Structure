#include <iostream>
using namespace std;

// Define a structure for a sparse matrix element
struct SparseElement {
    int row;
    int col;
    int value;
};

class Matrix {
public:
    int A[10][10];
    int B[10][10];
    SparseElement sparseA[100];
    SparseElement sparseB[100];
    int r1, r2, c1, c2;
    int nonZeroA, nonZeroB; // Number of non-zero elements

    void menu();
    void read();
    void dis();
    void add();
    void sub();
    void convertToSparse();
    void displaySparse(SparseElement sparse[], int nonZero, const char* name);
};

int main() {
    Matrix obj;
    obj.menu();
    return 0;
}

void Matrix::read() {
    cout << "Enter the number of rows and columns for matrix1 (r1 c1): \n";
    cin >> r1 >> c1;

    cout << "Enter the number of rows and columns for matrix2 (r2 c2): \n";
    cin >> r2 >> c2;

    if (r1 != r2 || c1 != c2) {
        cout << "Matrices must have the same dimensions for addition or subtraction.\n";
        exit(1);
    }

    cout << "Enter elements for matrix1:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements for matrix2:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    // Convert matrices to sparse representation
    convertToSparse();
}

void Matrix::convertToSparse() {
    nonZeroA = 0;
    nonZeroB = 0;
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (A[i][j] != 0) {
                sparseA[nonZeroA++] = {i, j, A[i][j]};
            }
        }
    }

    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            if (B[i][j] != 0) {
                sparseB[nonZeroB++] = {i, j, B[i][j]};
            }
        }
    }
}

void Matrix::dis() {
    cout << "Matrix A:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Matrix B:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }

    displaySparse(sparseA, nonZeroA, "Sparse Matrix A");
    displaySparse(sparseB, nonZeroB, "Sparse Matrix B");
}

void Matrix::displaySparse(SparseElement sparse[], int nonZero, const char* name) {
    cout << name << " (Sparse Representation):\n";
    for (int i = 0; i < nonZero; i++) {
        cout << "Row: " << sparse[i].row << " Col: " << sparse[i].col << " Value: " << sparse[i].value << endl;
    }
    cout << endl;
}

void Matrix::add() {
    if (r1 != r2 || c1 != c2) {
        cout << "Addition cannot take place! Matrices must have the same dimensions.\n";
        return;
    }

    int C[10][10] = {0}; // Initialize result matrix with zeros

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Addition matrix is:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}

void Matrix::sub() {
    if (r1 != r2 || c1 != c2) {
        cout << "Subtraction cannot take place! Matrices must have the same dimensions.\n";
        return;
    }

    int C[10][10] = {0}; // Initialize result matrix with zeros

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "Subtraction matrix is:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}

void Matrix::menu() {
    int choice;
    do {
        cout << "1. Read Matrix1 and Matrix2\n";
        cout << "2. Display Matrix\n";
        cout << "3. Addition of Matrix\n";
        cout << "4. Subtraction of Matrix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                read();
                break;
            case 2:
                dis();
                break;
            case 3:
                add();
                break;
            case 4:
                sub();
                break;
            case 5:
                cout << "Exiting the Menu\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);
}

