#include <iostream>
#include <vector>

void gaussElimination(std::vector<std::vector<double>>& A, std::vector<double>& B, std::vector<double>& X) {
    int n = B.size();

    for (int i = 0; i < n; ++i) {
        int max_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(A[k][i]) > std::abs(A[max_row][i])) {
                max_row = k;
            }
        }

        if (max_row != i) {
            A[i].swap(A[max_row]);
            std::swap(B[i], B[max_row]);
        }

        for (int j = i + 1; j < n; ++j) {
            double factor = A[j][i] / A[i][i];
            for (int k = i + 1; k < n; ++k) {
                A[j][k] -= factor * A[i][k];
            }
            B[j] -= factor * B[i];
        }
    }

    X.resize(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * X[j];
        }
        X[i] = (B[i] - sum) / A[i][i];
    }
}

int main() {
    // Заданные узлы интерполяции
    std::vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};
    std::vector<double> y = {0.0, 0.5, 0.86603, 1.0, 0.86603};

    int n = x.size();

    // Вычисление разностей второго порядка
    std::vector<double> h(n - 1);
    for (int i = 0; i < n - 1; ++i)
        h[i] = x[i + 1] - x[i];

    // Построение системы линейных уравнений для кубического сплайна
    std::vector<std::vector<double>> A(n, std::vector<double>(n, 0.0));
    std::vector<double> B(n, 0.0);

    for (int i = 1; i < n - 1; ++i) {
        A[i][i - 1] = h[i - 1];
        A[i][i] = 2.0 * (h[i - 1] + h[i]);
        A[i][i + 1] = h[i];
        B[i] = 3.0 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1]);
    }

    // Условие нулевой кривизны на концах
    A[0][0] = 1.0;
    A[n - 1][n - 1] = 1.0;

    // Решение системы линейных уравнений
    std::vector<double> c(n, 0.0);
    gaussElimination(A, B, c);

    // Нахождение остальных коэффициентов сплайна
    std::vector<double> b(n - 1, 0.0);
    std::vector<double> d(n - 1, 0.0);

    for (int i = 0; i < n - 1; ++i) {
        b[i] = (y[i + 1] - y[i]) / h[i] - h[i] * (2.0 * c[i] + c[i + 1]) / 3.0;
        d[i] = (c[i + 1] - c[i]) / (3.0 * h[i]);
    }

    // Вывод коэффициентов сплайна
    std::cout << "Spline coefficients:" << std::endl;
    for (int i = 0; i < n - 1; ++i) {
        std::cout << "S" << i << "(x) = " << y[i] << " + " << b[i] << "(x - " << x[i] << ") + " << c[i] << "(x - " << x[i] << ")^2 + " << d[i] << "(x - " << x[i] << ")^3 for x in [" << x[i] << ", " << x[i + 1] << "]" << std::endl;
    }

    // Вычисление значения сплайна в точке x = 1.5
    double x_interpol = 1.5;
    int segment = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (x[i] <= x_interpol && x_interpol <= x[i + 1]) {
            segment = i;
            break;
        }
    }

    double result = y[segment] + b[segment] * (x_interpol - x[segment]) + c[segment] * ((x_interpol - x[segment]) * (x_interpol - x[segment])) + d[segment] * ((x_interpol - x[segment]) * (x_interpol - x[segment]) * (x_interpol - x[segment]));
    std::cout << "Value of the spline at x = " << x_interpol << ": " << result << std::endl;

    return 0;
}
