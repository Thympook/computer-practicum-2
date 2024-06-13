import numpy as np

# Функция f(x1, x2)
def f(x1, x2):
    return x1**2 + np.exp(x1**2 + x2**2) + 4*x1 + 3*x2

# Градиент функции f
def grad_f(x1, x2):
    df_dx1 = 2*x1 + 2*x1*np.exp(x1**2 + x2**2) + 4
    df_dx2 = 2*x2*np.exp(x1**2 + x2**2) + 3
    return np.array([df_dx1, df_dx2])

# Метод наискорейшего спуска
def gradient_descent(alpha, max_iters, tol):
    x = np.array([0.0, 0.0])  # начальная точка
    for i in range(max_iters):
        grad = grad_f(x[0], x[1])
        x_new = x - alpha * grad
        
        # Проверка на сходимость
        if np.linalg.norm(x_new - x) < tol:
            break
        
        x = x_new
        
    return x

# Параметры
alpha = 0.01  # шаг градиентного спуска
max_iters = 1000
tol = 1e-6

# Поиск оптимума
opt_x = gradient_descent(alpha, max_iters, tol)

# Результаты
print("Optimal x1:", opt_x[0])
print("Optimal x2:", opt_x[1])
print("Optimal f(x1, x2):", f(opt_x[0], opt_x[1]))
