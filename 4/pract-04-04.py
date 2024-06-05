import numpy as np

def gauss_seidel(A, b, tolerance=0.01, max_iterations=1000):
    n = len(b)
    x = np.zeros(n)
    
    for iteration in range(max_iterations):
        x_old = x.copy()
        
        for i in range(n):
            sigma = sum(A[i][j] * x[j] for j in range(n) if j != i)
            x[i] = (b[i] - sigma) / A[i][i]
        
        error = np.linalg.norm(x - x_old, ord=np.inf)
        if error < tolerance:
            break
            
    return x

A = np.array([
    [-18, 9, -1, -8],
    [6, 22, 9, 0],
    [-4, 2, -16, 9],
    [1, 6, -1, -14]
], dtype=float)

b = np.array([-60, -109, -103, -33], dtype=float)

x = gauss_seidel(A, b)

print("Решение системы методом Зейделя:")
for i in range(len(x)):
    print(f"x{i + 1} = {x[i]:.4f}")
