import random
import math

# Функция для генерации случайного числа в диапазоне от -10 до 10
def get_random_number():
    return random.uniform(-10, 10)

# Генерация случайных параметров для параболического цилиндра, плоскости, прямой и точки
a = get_random_number()  # Коэффициент уравнения параболического цилиндра z = ax^2
b, c, d = get_random_number(), get_random_number(), get_random_number()  # Уравнение плоскости bx + cy + dz + e = 0
e = get_random_number()
m, n, p = get_random_number(), get_random_number(), get_random_number()  # Уравнение прямой x = mt + x0, y = nt + y0, z = pt + z0
x0, y0, z0 = get_random_number(), get_random_number(), get_random_number()
x, y, z = get_random_number(), get_random_number(), get_random_number()  # Точка (x, y, z)

# Проверка, принадлежит ли точка параболическому цилиндру
def is_point_on_parabolic_cylinder(a, x, y, z):
    return math.isclose(z, a * x**2, rel_tol=1e-9)

# Проверка, пересекает ли плоскость параболический цилиндр
def does_plane_intersect_cylinder(a, b, c, d, e):
    return not math.isclose(b**2 - 4 * a * d, 0, rel_tol=1e-9)

# Проверка, пересекает ли прямая параболический цилиндр
def does_line_intersect_cylinder(a, m, n, p, x0, y0, z0):
    # Подставим x = mt + x0 и z = pt + z0 в уравнение параболического цилиндра z = ax^2
    # Получим pt + z0 = a * (mt + x0)^2, решаем это квадратное уравнение относительно t
    A = a * m**2
    B = 2 * a * m * x0
    C = a * x0**2 - z0
    discriminant = B**2 - 4 * A * C
    return discriminant >= 0

# Вывод результатов
point_on_cylinder = is_point_on_parabolic_cylinder(a, x, y, z)
plane_intersects_cylinder = does_plane_intersect_cylinder(a, b, c, d, e)
line_intersects_cylinder = does_line_intersect_cylinder(a, m, n, p, x0, y0, z0)

print(f"Parabolic cylinder: z = {a}x^2")
print(f"Plane: {b}x + {c}y + {d}z + {e} = 0")
print(f"Line: x = {m}t + {x0}, y = {n}t + {y0}, z = {p}t + {z0}")
print(f"Point: ({x}, {y}, {z})")
print(f"Does the point lie on the parabolic cylinder? {'Yes' if point_on_cylinder else 'No'}")
print(f"Does the plane intersect the parabolic cylinder? {'Yes' if plane_intersects_cylinder else 'No'}")
print(f"Does the line intersect the parabolic cylinder? {'Yes' if line_intersects_cylinder else 'No'}")
