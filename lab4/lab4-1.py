import numpy as np

# Определение коэффициентов матрицы и вектора правых частей
A = np.array([
    [-8,  5,  8, -6],
    [ 2,  7, -8, -1],
    [-5, -4,  1, -6],
    [ 5, -9, -2,  8]
], dtype=float)

B = np.array([-144, 25, -21, 103], dtype=float)

# Метод обратной матрицы
def inverse_matrix_method(A, B):
    A_inv = np.linalg.inv(A)
    X = np.dot(A_inv, B)
    return X

# Метод Гаусса
def gauss_method(A, B):
    n = len(B)
    
    # Прямой ход
    for i in range(n):
        # Поиск максимального элемента для текущего столбца
        max_row = i + np.argmax(np.abs(A[i:, i]))
        
        # Поменять местами строки
        A[[i, max_row]] = A[[max_row, i]]
        B[[i, max_row]] = B[[max_row, i]]
        
        # Приведение к треугольному виду
        for j in range(i + 1, n):
            factor = A[j, i] / A[i, i]
            A[j, i:] -= factor * A[i, i:]
            B[j] -= factor * B[i]
    
    # Обратный ход
    X = np.zeros(n)
    for i in range(n - 1, -1, -1):
        X[i] = (B[i] - np.dot(A[i, i + 1:], X[i + 1:])) / A[i, i]
    
    return X

# Решение системы методом обратной матрицы
X_inverse = inverse_matrix_method(A.copy(), B.copy())

# Решение системы методом Гаусса
X_gauss = gauss_method(A.copy(), B.copy())

print("Solution using inverse matrix method:")
print(X_inverse)

print("Solution using Gauss method:")
print(X_gauss)
