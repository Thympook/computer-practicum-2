import numpy as np

# Определение функции
def f1(x):
    return x**4 / (12 + x**2)

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

# Параметры
a, b = 1, 2
n = 1000  # Количество интервалов

# Вычисление интегралов
rect_result = rectangle_method(f1, a, b, n)
trap_result = trapezoidal_method(f1, a, b, n)
simp_result = simpson_method(f1, a, b, n)

print(f"Rectangle Method: {rect_result}")
print(f"Trapezoidal Method: {trap_result}")
print(f"Simpson's Method: {simp_result}")
