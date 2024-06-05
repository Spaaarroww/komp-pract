import numpy as np

# Данные точки
points = np.array([
    [0.0, 0.0],
    [1.0, 0.0],
    [2.0, 0.5],
    [3.0, 2.0],
    [4.0, 0.86603]
])

x_points = points[:, 0]
y_points = points[:, 1]

# Вычисление коэффициентов кубического сплайна
def compute_spline_coefficients(x, y):
    n = len(x) - 1
    h = np.diff(x)
    alpha = np.zeros(n)
    for i in range(1, n):
        alpha[i] = (3 / h[i] * (y[i + 1] - y[i]) - 3 / h[i - 1] * (y[i] - y[i - 1]))

    l = np.ones(n + 1)
    mu = np.zeros(n + 1)
    z = np.zeros(n + 1)
    c = np.zeros(n + 1)
    b = np.zeros(n)
    d = np.zeros(n)

    for i in range(1, n):
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1]
        mu[i] = h[i] / l[i]
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i]

    l[n] = 1

    for j in range(n - 1, -1, -1):
        c[j] = z[j] - mu[j] * c[j + 1]
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3
        d[j] = (c[j + 1] - c[j]) / (3 * h[j])

    return y[:-1], b, c[:-1], d

# Вычисление значения функции в точке x^* с использованием кубического сплайна
def evaluate_spline(x, y, b, c, d, x_star):
    n = len(x) - 1
    i = n - 1
    while i > 0 and x_star < x[i]:
        i -= 1
    dx = x_star - x[i]
    return y[i] + b[i] * dx + c[i] * dx**2 + d[i] * dx**3

# Вычисление коэффициентов
a, b, c, d = compute_spline_coefficients(x_points, y_points)

# Точка, в которой нужно вычислить значение функции
x_star = 1.5
result = evaluate_spline(x_points, a, b, c, d, x_star)

print(f"The value of the function at x = {x_star} is {result}")
