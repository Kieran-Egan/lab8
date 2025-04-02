// matrix_operations.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<vector<int>> Matrix;

// function to print a matrix
void printMatrix(const Matrix &mat) {
    for (const auto &row : mat) {
        for (int val : row) {
            cout << setw(4) << val;
        }
        cout << "\n";
    }
}

// function to read matrices from a file
bool readMatrices(const string &filename, int &N, Matrix &mat1, Matrix &mat2) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return false;
    }

    infile >> N;
    mat1.assign(N, vector<int>(N));
    mat2.assign(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            infile >> mat1[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            infile >> mat2[i][j];

    return true;
}

// function to add matrices
Matrix addMatrices(const Matrix &A, const Matrix &B) {
    int N = A.size();
    Matrix result(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// function to multiply matrices
Matrix multiplyMatrices(const Matrix &A, const Matrix &B) {
    int N = A.size();
    Matrix result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

// function to sum diagonals
void sumDiagonals(const Matrix &mat) {
    int N = mat.size();
    int mainDiag = 0, secDiag = 0;
    for (int i = 0; i < N; ++i) {
        mainDiag += mat[i][i];
        secDiag += mat[i][N - 1 - i];
    }
    cout << "Main Diagonal Sum: " << mainDiag << "\n";
    cout << "Secondary Diagonal Sum: " << secDiag << "\n";
}

// function to swap rows
void swapRows(Matrix &mat, int r1, int r2) {
    int N = mat.size();
    if (r1 >= 0 && r2 >= 0 && r1 < N && r2 < N) {
        swap(mat[r1], mat[r2]);
    }
}

// function to swap columns
void swapCols(Matrix &mat, int c1, int c2) {
    int N = mat.size();
    if (c1 >= 0 && c2 >= 0 && c1 < N && c2 < N) {
        for (int i = 0; i < N; ++i)
            swap(mat[i][c1], mat[i][c2]);
    }
}

// function to update a matrix value
void updateMatrix(Matrix &mat, int r, int c, int val) {
    int N = mat.size();
    if (r >= 0 && c >= 0 && r < N && c < N) {
        mat[r][c] = val;
    }
}

int main() {
    int N;
    Matrix mat1, mat2;

    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    if (!readMatrices(filename, N, mat1, mat2)) return 1;

    cout << "Matrix 1:\n";
    printMatrix(mat1);
    cout << "\nMatrix 2:\n";
    printMatrix(mat2);

    cout << "\nMatrix Addition:\n";
    printMatrix(addMatrices(mat1, mat2));

    cout << "\nMatrix Multiplication:\n";
    printMatrix(multiplyMatrices(mat1, mat2));

    cout << "\nDiagonal Sums (Matrix 1):\n";
    sumDiagonals(mat1);

    cout << "\nSwap rows 0 and 1 in Matrix 1:\n";
    swapRows(mat1, 0, 1);
    printMatrix(mat1);

    cout << "\nSwap columns 0 and 1 in Matrix 1:\n";
    swapCols(mat1, 0, 1);
    printMatrix(mat1);

    cout << "\nUpdate element (2,2) to 99 in Matrix 1:\n";
    updateMatrix(mat1, 2, 2, 99);
    printMatrix(mat1);

    return 0;
}
