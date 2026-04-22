#include <iostream>
using namespace std;

struct Matrix {
    double a[3][3];
};

// Multiply matrix 3x3
Matrix multiply(const Matrix& x, const Matrix& y) {
    Matrix res{0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.a[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                res.a[i][j] += x.a[i][k] * y.a[k][j];
            }
        }
    }

    return res;
}

// Identity Matrix 3x3
Matrix identity() {
    Matrix I{0};
    for (int i = 0; i < 3; i++) {
        I.a[i][i] = 1;
    }
    return I;
}

// a^b
Matrix power(Matrix a, int b) {
    if (b == 0)
        return identity();

    Matrix res = power(a, b / 2);

    if (b % 2 == 1)
        return multiply(multiply(res, res), a);
    else
        return multiply(res, res);
}

// Tribonacci 
double slowTribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;

    Matrix A = {{
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    }};

    Matrix P = power(A, n - 2);

    // Multiply by original matrix [T2, T1, T0]^T = [1, 0, 0]^T
    // => first element of P
    return P.a[0][0];
}

int main() {
    int n;
    cin >> n;

    cout << slowTribonacci(n) << endl;

    return 0;
}