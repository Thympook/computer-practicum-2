import numpy as np

# Определение коэффициентов матрицы и вектора правых частей
A = np.array([
    [15,  0,  7,  5],
    [-3, -14, -6, -1],
    [-2,  9,  13,  2],
    [ 4, -1,  3,  9]
], dtype=float)

B = np.array([176, -111, 74, 76], dtype=float)

# Метод Зейделя
def gauss_seidel(A, B, initial_guess, tol=1e-6, max_iter=1000):
    n = len(B)
    X = initial_guess.copy()
    
    for iter_count in range(max_iter):
        X_old = X.copy()
        
        for i in range(n):
            sum1 = np.dot(A[i, :i], X[:i])
            sum2 = np.dot(A[i, i + 1:], X_old[i + 1:])
            X[i] = (B[i] - sum1 - sum2) / A[i, i]
        
        if np.linalg.norm(X - X_old, ord=np.inf) < tol:
            return X, iter_count + 1
    
    return X, max_iter

# Начальное предположение
initial_guess = np.zeros_like(B)

# Решение методом Зейделя
solution, iterations = gauss_seidel(A, B, initial_guess)

print("Solution using Gauss-Seidel method:")
print(solution)
print(f"Iterations: {iterations}")
