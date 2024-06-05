import numpy as np

# Функция f(x)
def f(x):
    return x[0]**2 + 3*x[1]**2 + np.cos(x[0] + x[1])

# Производная функции по x1
def df_dx1(x):
    return 2*x[0] - np.sin(x[0] + x[1])

# Производная функции по x2
def df_dx2(x):
    return 6*x[1] - np.sin(x[0] + x[1])

# Метод покоординатного спуска
def coordinate_descent(learning_rate, iterations):
    x = np.array([0, 0])  # Начальные значения
    for _ in range(iterations):
        # Обновление x1
        x[0] -= learning_rate * df_dx1(x)
        # Обновление x2
        x[1] -= learning_rate * df_dx2(x)
    return x

# Основная программа
learning_rate = 0.01
iterations = 1000
result = coordinate_descent(learning_rate, iterations)

# Вывод результатов
print("Optimal x1:", result[0])
print("Optimal x2:", result[1])
print("Minimum value of f(x):", f(result))
