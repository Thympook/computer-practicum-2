import numpy as np

def newton_interpolation(x, y, x_interpol):
    n = len(x)
    c = np.zeros(n)
    c[0] = y[0]

    # Вычисление разделенных разностей
    for j in range(1, n):
        for i in range(n-1, j-1, -1):
            y[i] = (y[i] - y[i-1]) / (x[i] - x[i-j])
        c[j] = y[j]

    # Вычисление значения интерполяционного многочлена
    result = c[0]
    for j in range(1, n):
        term = c[j]
        for i in range(j):
            term *= (x_interpol - x[i])
        result += term

    return result

# Заданные узлы интерполяции и значения функции
x = np.array([0.1 * np.pi, 0.2 * np.pi, 0.3 * np.pi, 0.4 * np.pi])
y = np.sin(x)

# Точка, в которой вычисляем значение интерполяционного многочлена
x_interpol = 0.25 * np.pi

# Вычисление значения интерполяционного многочлена в точке x_interpol
interpolated_value = newton_interpolation(x, y, x_interpol)

# Вычисление погрешности интерполяции в точке x_interpol
exact_value = np.sin(x_interpol)
error = abs(exact_value - interpolated_value)

print("Значение интерполяционного многочлена в точке x =", x_interpol, ":", interpolated_value)
print("Значение функции в точке x =", x_interpol, ":", exact_value)
print("Погрешность интерполяции в точке x =", x_interpol, ":", error)
