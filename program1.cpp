#include <iostream>
using namespace std;

// Function to input a matrix
void inputMatrix(int matrix[10][10], int rows, int cols, string name) {
    cout << "Enter elements of Matrix " << name << " (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << name << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols, string name) {
    cout << "\nMatrix " << name << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function for matrix addition
void addMatrix(int A[10][10], int B[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[i][j] = A[i][j] + B[i][j];
}

// Function for matrix subtraction
void subtractMatrix(int A[10][10], int B[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[i][j] = A[i][j] - B[i][j];
}

// Function for matrix multiplication
void multiplyMatrix(int A[10][10], int B[10][10], int result[10][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < c1; ++k)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main() {
    int A[10][10], B[10][10], result[10][10];
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for Matrix B: ";
    cin >> r2 >> c2;

    // Input matrices
    inputMatrix(A, r1, c1, "A");
    inputMatrix(B, r2, c2, "B");

    displayMatrix(A, r1, c1, "A");
    displayMatrix(B, r2, c2, "B");

    // Addition and subtraction only possible if sizes are same
    if (r1 == r2 && c1 == c2) {
        addMatrix(A, B, result, r1, c1);
        displayMatrix(result, r1, c1, "A + B");

        subtractMatrix(A, B, result, r1, c1);
        displayMatrix(result, r1, c1, "A - B");
    } else {
        cout << "\nAddition and Subtraction not possible (Matrix sizes must be same).\n";
    }

    // Multiplication possible if c1 == r2
    if (c1 == r2) {
        multiplyMatrix(A, B, result, r1, c1, c2);
        displayMatrix(result, r1, c2, "A x B");
    } else {
        cout << "\nMultiplication not possible (Columns of A must equal Rows of B).\n";
    }

    return 0;
}
