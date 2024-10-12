#include <iostream>
#include <iomanip>
using namespace std;
void InputMatrix(double** matrix, const int size);
void PrintMatrix(double** matrix, const int size);
void ArrangeMaxOnDiagonal(double** matrix, const int size);
int FindFirstRowWithoutPositive(double** matrix, const int size);
int main() {
    int n;
    cout << "Enter the size of the square matrix (n x n): ";
    cin >> n;
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new double[n];
    InputMatrix(matrix, n);
    cout << "Initial matrix:" << endl;
    PrintMatrix(matrix, n);
    ArrangeMaxOnDiagonal(matrix, n);
    cout << "Matrix after rearranging max elements on the diagonal:" << endl;
    PrintMatrix(matrix, n);
    int firstRowWithoutPositive = FindFirstRowWithoutPositive(matrix, n);
    if (firstRowWithoutPositive != -1)
        cout << "First row without positive elements: " << firstRowWithoutPositive << endl;
    else
        cout << "All rows contain positive elements." << endl;
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}
void InputMatrix(double** matrix, const int size) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}
void PrintMatrix(double** matrix, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(8) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void ArrangeMaxOnDiagonal(double** matrix, const int size) {
    for (int i = 0; i < size; i++) {
        int maxRow = i, maxCol = i;
        for (int row = i; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (matrix[row][col] > matrix[maxRow][maxCol]) {
                    maxRow = row;
                    maxCol = col;
                }
            }
        }
        swap(matrix[i][i], matrix[maxRow][maxCol]);
    }
}
int FindFirstRowWithoutPositive(double** matrix, const int size) {
    for (int i = 0; i < size; i++) {
        bool hasPositive = false;
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] > 0) {
                hasPositive = true;
                break;
            }
        }
        if (!hasPositive)
            return i;
    }
    return -1;
}
