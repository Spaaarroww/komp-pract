import numpy as np

# Функция для вычисления детерминанта матрицы 3x3
def determinant(matrix):
    return (matrix[0, 0] * (matrix[1, 1] * matrix[2, 2] - matrix[1, 2] * matrix[2, 1]) -
            matrix[0, 1] * (matrix[1, 0] * matrix[2, 2] - matrix[1, 2] * matrix[2, 0]) +
            matrix[0, 2] * (matrix[1, 0] * matrix[2, 1] - matrix[1, 1] * matrix[2, 0]))

# Метод Крамера
def cramer_method(A, b):
    detA = determinant(A)
    if detA == 0:
        raise ValueError("Matrix is singular and cannot be solved by Cramer's rule.")
    
    x = np.zeros(3)
    for i in range(3):
        Ai = A.copy()
        Ai[:, i] = b
        x[i] = determinant(Ai) / detA
    return x

# Метод Якоби
def jacobi_method(A, b, max_iterations=1000, tolerance=1e-10):
    n = len(b)
    x = np.zeros(n)
    x_old = np.zeros(n)

    for iteration in range(max_iterations):
        x_old = x.copy()
        for i in range(n):
            sigma = sum(A[i][j] * x_old[j] for j in range(n) if j != i)
            x[i] = (b[i] - sigma) / A[i, i]
        
        # Проверка на сходимость
        if np.linalg.norm(x - x_old, ord=np.inf) < tolerance:
            break
    return x

A = np.array([[5, -2, -1],
              [2, -1, -1],
              [2, -4, -8]], dtype=float)
b = np.array([0, -1, 1], dtype=float)

try:
    x_cramer = cramer_method(A, b)
    print("Решение системы методом Крамера:")
    for i in range(len(x_cramer)):
        print(f"x{i + 1} = {x_cramer[i]}")
except ValueError as e:
    print(e)

x_jacobi = jacobi_method(A, b)
print("Решение системы методом Якоби:")
for i in range(len(x_jacobi)):
    print(f"x{i + 1} = {x_jacobi[i]}")

