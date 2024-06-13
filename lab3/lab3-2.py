import numpy as np
from scipy.integrate import quad

# Определение функции
def f2(x):
    return np.exp(-2 * x) * np.sin(12 * x)

# Метод прямоугольников
def rectangle_method(f, a, b, n):
    h = (b - a) / n
    result = sum(f(a + i * h) for i in range(n)) * h
    return result

# Метод трапеций
def trapezoidal_method(f, a, b, n):
    h = (b - a) / n
    result = (f(a) + f(b)) / 2 + sum(f(a + i * h) for i in range(1, n))
    return result * h

# Метод Симпсона
def simpson_method(f, a, b, n):
    if n % 2:
        n += 1  # n должно быть четным
    h = (b - a) / n
    result = f(a) + f(b) + 4 * sum(f(a + i * h) for i in range(1, n, 2)) + 2 * sum(f(a + i * h) for i in range(2, n-1, 2))
    return result * h / 3

# Используем scipy для интегрирования на бесконечном интервале
integral_value, error = quad(f2, 0, np.inf)

# Вывод результата с использованием scipy
print(f"Integration using scipy: {integral_value} (error: {error})")

# Параметры для численного интегрирования на конечном интервале
a, b = 0, 10  # Интервал интегрирования [0, 10]
n = 1000  # Количество интервалов

# Вычисление интегралов на конечном интервале
rect_result = rectangle_method(f2, a, b, n)
trap_result = trapezoidal_method(f2, a, b, n)
simp_result = simpson_method(f2, a, b, n)

print(f"Rectangle Method (0 to 10): {rect_result}")
print(f"Trapezoidal Method (0 to 10): {trap_result}")
print(f"Simpson's Method (0 to 10): {simp_result}")
