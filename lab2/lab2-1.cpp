#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Функция для генерации случайного числа в диапазоне от -10 до 10
int getRandomNumber() {
    return rand() % 21 - 10;
}

// Функция для нахождения расстояния от точки до прямой
double distancePointToLine(double A, double B, double C, double x, double y) {
    return std::abs(A * x + B * y + C) / std::sqrt(A * A + B * B);
}

// Функция для нахождения точки пересечения двух прямых
bool intersectionOfLines(double A1, double B1, double C1, double A2, double B2, double C2, double &x, double &y) {
    double det = A1 * B2 - A2 * B1;
    if (det == 0) {
        return false; // Прямые параллельны или совпадают
    } else {
        x = (B2 * C1 - B1 * C2) / det;
        y = (A1 * C2 - A2 * C1) / det;
        return true;
    }
}

// Функция для нахождения угла между двумя прямыми
double angleBetweenLines(double A1, double B1, double A2, double B2) {
    double dotProduct = A1 * A2 + B1 * B2;
    double magnitude1 = std::sqrt(A1 * A1 + B1 * B1);
    double magnitude2 = std::sqrt(A2 * A2 + B2 * B2);
    return std::acos(dotProduct / (magnitude1 * magnitude2));
}


int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Генерация случайных параметров для прямых и точки
    double A1 = getRandomNumber();
    double B1 = getRandomNumber();
    double C1 = getRandomNumber();
    double A2 = getRandomNumber();
    double B2 = getRandomNumber();
    double C2 = getRandomNumber();
    double x = getRandomNumber();
    double y = getRandomNumber();

    double distance1 = distancePointToLine(A1, B1, C1, x, y);
    double distance2 = distancePointToLine(A2, B2, C2, x, y);
    double intersectionX, intersectionY;
    if (intersectionOfLines(A1, B1, C1, A2, B2, C2, intersectionX, intersectionY)) {
        double distanceToIntersection = std::sqrt(std::pow(intersectionX - x, 2) + std::pow(intersectionY - y, 2));
        double angle = angleBetweenLines(A1, B1, A2, B2);

        std::cout << "Line 1: " << A1 << "x + " << B1 << "y + " << C1 << " = 0" << std::endl;
        std::cout << "Line 2: " << A2 << "x + " << B2 << "y + " << C2 << " = 0" << std::endl;
        std::cout << "Point: (" << x << ", " << y << ")" << std::endl;
        std::cout << "Distance from point to line 1: " << distance1 << std::endl;
        std::cout << "Distance from point to line 2: " << distance2 << std::endl;
        std::cout << "Intersection point: (" << intersectionX << ", " << intersectionY << ")" << std::endl;
        std::cout << "Distance from point to intersection: " << distanceToIntersection << std::endl;
        std::cout << "Angle between lines: " << angle * 180 / M_PI << " degrees" << std::endl;
    } else {
        std::cout << "The lines are parallel and do not intersect." << std::endl;
    }

    return 0;
}
