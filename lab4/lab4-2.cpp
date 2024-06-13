#include <iostream>
#include <cmath>

// Размерность системы
const int N = 3;

// Определение коэффициентов матрицы и вектора правых частей
double A[N][N] = {
    {-10, -1, 3},
    {8, 7, 2},
    {6, 6, 2}
};

double B[N] = {-1, 0, 2};

// Метод Крамера для решения системы
double* cramerMethod(double A[N][N], double B[N]) {
    static double result[N];
    double det_A = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    if (std::abs(det_A) < 1e-6) {
        std::cout << "Determinant is close to zero. Method cannot be applied." << std::endl;
        return nullptr;
    }

    double A_temp[N][N];

    for (int i = 0; i < N; ++i) {
        std::copy(&A[0][0], &A[0][0] + N * N, &A_temp[0][0]);
        for (int j = 0; j < N; ++j)
            A_temp[j][i] = B[j];

        double det_A_temp = A_temp[0][0] * (A_temp[1][1] * A_temp[2][2] - A_temp[1][2] * A_temp[2][1]) - A_temp[0][1] * (A_temp[1][0] * A_temp[2][2] - A_temp[1][2] * A_temp[2][0]) + A_temp[0][2] * (A_temp[1][0] * A_temp[2][1] - A_temp[1][1] * A_temp[2][0]);
        result[i] = det_A_temp / det_A;
    }

    return result;
}

// Метод Якоби для решения системы
double* jacobiMethod(double A[N][N], double B[N], double initial_guess[N], double tolerance = 1e-6, int max_iter = 1000) {
    static double result[N];
    double X[N], X_old[N];

    for (int i = 0; i < N; ++i)
        X_old[i] = initial_guess[i];

    for (int iter_count = 0; iter_count < max_iter; ++iter_count) {
        for (int i = 0; i < N; ++i) {
            double sum = 0.0;
            for (int j = 0; j < N; ++j)
                if (i != j)
                    sum += A[i][j] * X_old[j];
            X[i] = (B[i] - sum) / A[i][i];
        }

        bool converged = true;
        for (int i = 0; i < N; ++i) {
            if (std::abs(X[i] - X_old[i]) > tolerance) {
                converged = false;
                break;
            }
        }

        if (converged) {
            std::copy(std::begin(X), std::end(X), std::begin(result));
            return result;
        }

        std::copy(std::begin(X), std::end(X), std::begin(X_old));
    }

    std::cout << "Maximum number of iterations reached. Solution may not be accurate." << std::endl;
    std::copy(std::begin(X), std::end(X), std::begin(result));
    return result;
}

int main() {
    double initial_guess[N] = {-25, 46, -65};

    // Решение методом Крамера
    double* cramer_solution = cramerMethod(A, B);
    if (cramer_solution) {
        std::cout << "Solution using Cramer's method:" << std::endl;
        for (int i = 0; i < N; ++i)
            std::cout << "x_" << i+1 << " = " << cramer_solution[i] << std::endl;
    }

    std::cout << std::endl;

    // Решение методом Якоби
    double* jacobi_solution = jacobiMethod(A, B, initial_guess);
    if (jacobi_solution) {
        std::cout << "Solution using Jacobi method:" << std::endl;
        for (int i = 0; i < N; ++i)
            std::cout << "x_" << i+1 << " = " << jacobi_solution[i] << std::endl;
    }

    return 0;
}
