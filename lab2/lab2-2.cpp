#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Функция для генерации случайного числа в диапазоне от -10 до 10
int getRandomNumber() {
    return rand() % 21 - 10;
}

// Функция для нахождения длины вектора
double vectorLength(double x, double y, double z) {
    return std::sqrt(x * x + y * y + z * z);
}

// Функция для нахождения угла между двумя векторами
double angleBetweenVectors(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dotProduct = x1 * x2 + y1 * y2 + z1 * z2;
    double magnitude1 = vectorLength(x1, y1, z1);
    double magnitude2 = vectorLength(x2, y2, z2);
    return std::acos(dotProduct / (magnitude1 * magnitude2));
}

// Функция для нахождения суммы двух векторов
void vectorSum(double x1, double y1, double z1, double x2, double y2, double z2, double &x, double &y, double &z) {
    x = x1 + x2;
    y = y1 + y2;
    z = z1 + z2;
}

// Функция для нахождения разности двух векторов
void vectorDifference(double x1, double y1, double z1, double x2, double y2, double z2, double &x, double &y, double &z) {
    x = x1 - x2;
    y = y1 - y2;
    z = z1 - z2;
}

// Функция для проверки, параллельны ли два вектора
bool areVectorsParallel(double x1, double y1, double z1, double x2, double y2, double z2) {
    double crossProductX = y1 * z2 - z1 * y2;
    double crossProductY = z1 * x2 - x1 * z2;
    double crossProductZ = x1 * y2 - y1 * x2;
    return (crossProductX == 0 && crossProductY == 0 && crossProductZ == 0);
}

// Функция для нахождения векторного произведения двух векторов
void vectorCrossProduct(double x1, double y1, double z1, double x2, double y2, double z2, double &x, double &y, double &z) {
    x = y1 * z2 - z1 * y2;
    y = z1 * x2 - x1 * z2;
    z = x1 * y2 - y1 * x2;
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Генерация случайных координат для векторов
    double x1 = getRandomNumber();
    double y1 = getRandomNumber();
    double z1 = getRandomNumber();
    double x2 = getRandomNumber();
    double y2 = getRandomNumber();
    double z2 = getRandomNumber();

    double length1 = vectorLength(x1, y1, z1);
    double length2 = vectorLength(x2, y2, z2);
    double angleVectors = angleBetweenVectors(x1, y1, z1, x2, y2, z2) * 180 / M_PI;
    double sumX, sumY, sumZ;
    double diffX, diffY, diffZ;
    vectorSum(x1, y1, z1, x2, y2, z2, sumX, sumY, sumZ);
    vectorDifference(x1, y1, z1, x2, y2, z2, diffX, diffY, diffZ);
    bool parallel = areVectorsParallel(x1, y1, z1, x2, y2, z2);
    double crossX, crossY, crossZ;
    vectorCrossProduct(x1, y1, z1, x2, y2, z2, crossX, crossY, crossZ);

    std::cout << "Vector 1: (" << x1 << ", " << y1 << ", " << z1 << ")" << std::endl;
    std::cout << "Vector 2: (" << x2 << ", " << y2 << ", " << z2 << ")" << std::endl;
    std::cout << "Length of vector 1: " << length1 << std::endl;
    std::cout << "Length of vector 2: " << length2 << std::endl;
    std::cout << "Angle between vectors: " << angleVectors << " degrees" << std::endl;
    std::cout << "Sum of vectors: (" << sumX << ", " << sumY << ", " << sumZ << ")" << std::endl;
    std::cout << "Difference of vectors: (" << diffX << ", " << diffY << ", " << diffZ << ")" << std::endl;
    std::cout << "Vectors are " << (parallel ? "parallel" : "not parallel") << std::endl;
    std::cout << "Cross product: (" << crossX << ", " << crossY << ", " << crossZ << ")" << std::endl;

    return 0;
}
