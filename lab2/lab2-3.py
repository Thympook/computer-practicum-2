import random
import math

# Функция для генерации случайного числа в диапазоне от -10 до 10
def get_random_number():
    return random.uniform(-10, 10)

# Генерация случайных параметров для эллипса и точки
a = abs(get_random_number())  # Длина большой полуоси (a > 0)
b = abs(get_random_number())  # Длина малой полуоси (b > 0)
x0 = get_random_number()      # Центр эллипса (x0, y0)
y0 = get_random_number()
x = get_random_number()       # Точка (x, y)
y = get_random_number()

# Проверка, принадлежит ли точка эллипсу
def is_point_on_ellipse(a, b, x0, y0, x, y):
    return math.isclose(((x - x0)**2 / a**2) + ((y - y0)**2 / b**2), 1, rel_tol=1e-9)

# Координаты фокусов эллипса
def ellipse_foci(a, b, x0, y0):
    c = math.sqrt(a**2 - b**2)
    return (x0 + c, y0), (x0 - c, y0)

# Эксцентриситет эллипса
def ellipse_eccentricity(a, b):
    return math.sqrt(1 - (b**2 / a**2))

# Расстояние от директрис до центра эллипса
def ellipse_directrices(a, e):
    return a / e

# Вывод результатов
point_on_ellipse = is_point_on_ellipse(a, b, x0, y0, x, y)
foci1, foci2 = ellipse_foci(a, b, x0, y0)
eccentricity = ellipse_eccentricity(a, b)
directrices_distance = ellipse_directrices(a, eccentricity)

print(f"Ellipse: (x - {x0})^2 / {a**2} + (y - {y0})^2 / {b**2} = 1")
print(f"Point: ({x}, {y})")
print(f"Does the point lie on the ellipse? {'Yes' if point_on_ellipse else 'No'}")
print(f"Foci: {foci1}, {foci2}")
print(f"Lengths of semi-axes: a = {a}, b = {b}")
print(f"Eccentricity: {eccentricity}")
print(f"Distance from directrices to center: {directrices_distance}")
