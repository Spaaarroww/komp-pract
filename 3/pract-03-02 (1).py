import numpy as np

# Функция, которую нужно интегрировать
def f(x):
    return np.exp(-2 * x) * np.sin(4 * x)

# Метод прямоугольников
def rectangle_method(a, b, n):
    h = (b - a) / n
    sum = 0.0
    for i in range(n):
        sum += f(a + i * h)
    return sum * h

# Метод трапеций
def trapezoidal_method(a, b, n):
    h = (b - a) / n
    sum = (f(a) + f(b)) / 2.0
    for i in range(1, n):
        sum += f(a + i * h)
    return sum * h

# Метод Симпсона
def simpson_method(a, b, n):
    h = (b - a) / n
    sum = f(a) + f(b)
    for i in range(1, n):
        sum += f(a + i * h) * (2 if i % 2 == 0 else 4)
    return sum * h / 3.0

# Главная функция
if __name__ == "__main__":
    a = 0.0
    b = 10.0  # Достаточно большой предел интегрирования для аппроксимации бесконечности
    n = 1000000  # Количество шагов

    rect_result = rectangle_method(a, b, n)
    trap_result = trapezoidal_method(a, b, n)
    simp_result = simpson_method(a, b, n)

    print("Rectangle Method: {:.6f}".format(rect_result))
    print("Trapezoidal Method: {:.6f}".format(trap_result))
    print("Simpson Method: {:.6f}".format(simp_result))
