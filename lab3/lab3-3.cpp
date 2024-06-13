#include <iostream>
#include <cmath>
#include <iomanip>

double sumSeries1(double tolerance) {
    double sum = 0.0;
    double term;
    int k = 1;

    do {
        term = (12.0 / std::pow(2, k-1)) + (std::pow(-1, k-1) / (2.0 * std::pow(3, k-1)));
        sum += term;
        k++;
    } while (std::fabs(term) >= tolerance);

    return sum;
}

int main() {
    const double tolerance = 1e-6;
    double result = sumSeries1(tolerance);

    std::cout << std::fixed << std::setprecision(7);
    std::cout << "Sum of the series: " << result << std::endl;

    return 0;
}
