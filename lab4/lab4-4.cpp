#include <iostream>
#include <vector>

void thomasAlgorithm(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, std::vector<double>& d) {
    int n = d.size();
    
    // Создание копии вектора b
    std::vector<double> bb = b;

    // Прямой проход
    for (int i = 1; i < n; ++i) {
        double m = a[i] / bb[i - 1];
        bb[i] -= m * c[i - 1];
        d[i] -= m * d[i - 1];
    }

    // Обратный проход
    d[n - 1] /= bb[n - 1];
    for (int i = n - 2; i >= 0; --i)
        d[i] = (d[i] - c[i] * d[i + 1]) / bb[i];
}

int main() {
    std::vector<double> a = {0, -8, 0, 0, 0};
    std::vector<double> b = {10, 16, -16, -16, 5};
    std::vector<double> c = {-1, 1, -6, -8, -13};
    std::vector<double> d = {16, -110, 24, -3, 87};

    thomasAlgorithm(a, b, c, d);

    std::cout << "Solution using Thomas Algorithm:" << std::endl;
    for (int i = 0; i < d.size(); ++i)
        std::cout << "x_" << i + 1 << " = " << d[i] << std::endl;

    return 0;
}
