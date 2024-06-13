#include <iostream>
#include <cmath>
#include <iomanip>

// Функция для вычисления суммы функционального ряда
double sumSeries2(double x, double tolerance) {
    double sum = 0.0;
    double term;
    int k = 1;

    do {
        term = std::pow(-1, k) / (std::sin(k * x) + 12 + k * k);
        sum += term;
        k++;
    } while (std::fabs(term) >= tolerance);

    return sum;
}

int main() {
    const double tolerance = 1e-6;
    double x;

    std::cout << "Enter the value of x: ";
    std::cin >> x;

    double result = sumSeries2(x, tolerance);

    std::cout << std::fixed << std::setprecision(7);
    std::cout << "Sum of the series for x = " << x << " is: " << result << std::endl;

    return 0;
}
