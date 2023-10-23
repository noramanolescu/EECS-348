#include <iostream>
#include <fstream>
using namespace std;

const int n_max = 100;
int matrixA[n_max][n_max]; // initialize Matrix A
int matrixB[n_max][n_max]; // initialize Matrix B
int matrixC[n_max][n_max]; // initialize third matrix to store operation results

// function to print matrix
void print_matrix(int n, int matrix[n_max][n_max]) {
    for (int w = 0; w < n; w++) {
        for (int x = 0; x < n; x++) {
            cout << matrix[w][x] << " ";
        }
        cout << "\n";
    }
}

// function to return the size of the matrix as an integer (first character of input file)
int return_size(string filename) {
    int n;
    ifstream input_file(filename);
    input_file >> n;
    input_file.close();
    return n;
}

// function to read file and store input as matrices in 2D arrays
void read_data(string filename, int &n) {
    ifstream input_file(filename);
    input_file >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input_file >> matrixA[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            input_file >> matrixB[k][l];
        }
    }
    input_file.close();
}

// matrix subtraction function
void subtract(int n, int matrix1[n_max][n_max], int matrix2[n_max][n_max], int matrix3[n_max][n_max]) {
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < n; q++) {
            matrix3[p][q] = matrix1[p][q] - matrix2[p][q];
        }
    }
}

// matrix addition function
void addition(int n, int matrix1[n_max][n_max], int matrix2[n_max][n_max], int matrix3[n_max][n_max]) {
    for (int r = 0; r < n; r++) {
        for (int s = 0; s < n; s++) {
            matrix3[r][s] = matrix1[r][s] + matrix2[r][s];
        }
    }
}

// matrix multiplication function
void multiplication(int n, int matrix1[n_max][n_max], int matrix2[n_max][n_max], int matrix3[n_max][n_max]) {
    for (int r = 0; r < n; r++) {
        for (int s = 0; s < n; s++) {
            int entry = 0;
            for (int t = 0; t < n; t++) {
                entry += matrix1[r][t] * matrix2[t][s];
            }
            matrix3[r][s] = entry;
        }
    }
}

int main() {
    cout << "Nora Manolescu\n" << "Lab #6: Matrix manipulation\n";
    int n;
    n = return_size("matrix_input.txt");
    read_data("matrix_input.txt", n);
    cout << "\nMatrix A:\n";
    print_matrix(n, matrixA);
    cout << "\nMatrix B:\n";
    print_matrix(n, matrixB);
    addition(n, matrixA, matrixB, matrixC);
    cout << "\nMatrix Sum (A + B)\n";
    print_matrix(n, matrixC);
    multiplication(n, matrixA, matrixB, matrixC);
    cout << "\nMatrix Product (A * B)\n";
    print_matrix(n, matrixC);
    subtract(n, matrixA, matrixB, matrixC);
    cout << "\nMatrix Difference (A - B)\n";
    print_matrix(n, matrixC);
    return 0;
}