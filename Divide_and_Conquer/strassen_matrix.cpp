#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> add(const vector<vector<int>> &A, const vector<vector<int>> &B, int n) {
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> subtract(const vector<vector<int>> &A, const vector<vector<int>> &B, int n) {
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

vector<vector<int>> multiply(const vector<vector<int>> &A, const vector<vector<int>> &B, int n) {
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

vector<vector<int>> strassen(const vector<vector<int>> &A, const vector<vector<int>> &B, int n) {
    if (n <= 2)
        return multiply(A, B, n);

    int newSize = n / 2;

    vector<vector<int>> A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize)),
                        A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize)),
                        B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    auto M1 = strassen(add(A11, A22, newSize), add(B11, B22, newSize), newSize);
    auto M2 = strassen(add(A21, A22, newSize), B11, newSize);
    auto M3 = strassen(A11, subtract(B12, B22, newSize), newSize);
    auto M4 = strassen(A22, subtract(B21, B11, newSize), newSize);
    auto M5 = strassen(add(A11, A12, newSize), B22, newSize);
    auto M6 = strassen(subtract(A21, A11, newSize), add(B11, B12, newSize), newSize);
    auto M7 = strassen(subtract(A12, A22, newSize), add(B21, B22, newSize), newSize);

    vector<vector<int>> C11 = add(subtract(add(M1, M4, newSize), M5, newSize), M7, newSize);
    vector<vector<int>> C12 = add(M3, M5, newSize);
    vector<vector<int>> C21 = add(M2, M4, newSize);
    vector<vector<int>> C22 = add(subtract(add(M1, M3, newSize), M2, newSize), M6, newSize);

    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

int main() {
    int n = 4;

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));

    int val = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = val++;

    val = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = val++;

    vector<vector<int>> C = strassen(A, B, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
