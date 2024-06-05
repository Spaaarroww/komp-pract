import numpy as np

def gaussian_elimination(A, b):
    n = len(b)
    for i in range(n):
        # Partial pivoting
        for k in range(i+1, n):
            if abs(A[i][i]) < abs(A[k][i]):
                A[[i, k]] = A[[k, i]]
                b[i], b[k] = b[k], b[i]
        
        # Elimination process
        for k in range(i+1, n):
            t = A[k][i] / A[i][i]
            A[k, i:] -= t * A[i, i:]
            b[k] -= t * b[i]
    
    # Back substitution
    x = np.zeros(n)
    for i in range(n-1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i+1:], x[i+1:])) / A[i, i]
    
    return x

# Матрица A и вектор b для метода Гаусса
A = np.array([[7, -5, 6, 7],
              [8, -1, -9, 1],
              [-3, 8, 8, 8],
              [2, -3, 6, -4]], dtype=float)

b = np.array([120, 31, 6, 25], dtype=float)

# Решение методом Гаусса
x_gauss = gaussian_elimination(A.copy(), b.copy())

print("Решение системы методом Гаусса:")
print(x_gauss)

# Решение матричным методом с использованием библиотеки NumPy
A_eigen = np.array([[7, -5, 6, 7],
                    [8, -1, -9, 1],
                    [-3, 8, 8, 8],
                    [2, -3, 6, -4]], dtype=float)

b_eigen = np.array([120, 31, 6, 25], dtype=float)

x_eigen = np.linalg.solve(A_eigen, b_eigen)

print("Решение системы матричным методом:")
print(x_eigen)
