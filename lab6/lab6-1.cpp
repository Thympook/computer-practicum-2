#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

// Функция f(x1, x2, x3)
double f(double x1, double x2, double x3) {
    return exp(pow(x1, 2) + pow(x2, 2)) + log(4 + pow(x2, 2) + 2 * pow(x3, 2));
}

// Производная f по x1
double df_dx1(double x1, double x2, double x3) {
    return 2 * x1 * exp(pow(x1, 2) + pow(x2, 2));
}

// Производная f по x2
double df_dx2(double x1, double x2, double x3) {
    return 2 * x2 * exp(pow(x1, 2) + pow(x2, 2)) + (2 * x2 / (4 + pow(x2, 2) + 2 * pow(x3, 2)));
}

// Производная f по x3
double df_dx3(double x1, double x2, double x3) {
    return (4 * x3 / (4 + pow(x2, 2) + 2 * pow(x3, 2)));
}

// Метод покоординатного спуска
void coordinate_descent(double& x1, double& x2, double& x3, double alpha, int max_iters, double tol) {
    for (int iter = 0; iter < max_iters; ++iter) {
        double x1_new = x1 - alpha * df_dx1(x1, x2, x3);
        double x2_new = x2 - alpha * df_dx2(x1, x2, x3);
        double x3_new = x3 - alpha * df_dx3(x1, x2, x3);

        if (abs(x1_new - x1) < tol && abs(x2_new - x2) < tol && abs(x3_new - x3) < tol) {
            break;
        }

        x1 = x1_new;
        x2 = x2_new;
        x3 = x3_new;
    }
}

int main() {
    double x1 = 0.5, x2 = 0.5, x3 = 0.5;
    double alpha = 0.01; // шаг градиентного спуска
    int max_iters = 1000;
    double tol = 1e-6;

    coordinate_descent(x1, x2, x3, alpha, max_iters, tol);

    cout << "Optimal x1: " << x1 << endl;
    cout << "Optimal x2: " << x2 << endl;
    cout << "Optimal x3: " << x3 << endl;
    cout << "Optimal f(x1, x2, x3): " << f(x1, x2, x3) << endl;

    return 0;
}
