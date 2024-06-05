import numpy as np

# Определение функции f(x1, x2)
def f(x1, x2):
    return 7*x1**2 + 2*x1*x2 + 5*x2**2 + x1 - 10*x2

# Вычисление градиента функции f в точке (x1, x2)
def gradient(x1, x2):
    grad_x1 = 14*x1 + 2*x2 + 1
    grad_x2 = 10*x2 + 2*x1 - 10
    return np.array([grad_x1, grad_x2])

# Реализация метода градиентного спуска
def gradient_descent(alpha, max_iter):
    # Начальные значения x1 и x2
    x = np.array([0.0, 0.0])
    
    for i in range(max_iter):
        # Вычисление градиента в текущей точке
        grad = gradient(x[0], x[1])
        
        # Обновление значений x1 и x2
        x = x - alpha * grad
        
        # Вывод текущей итерации, значений x1 и x2 и значения функции
        print(f"Итерация {i+1}: x1 = {x[0]}, x2 = {x[1]}, f(x1, x2) = {f(x[0], x[1])}")
        
        # Проверка на сходимость
        if np.linalg.norm(grad) < 1e-6:
            break
            
    return x

# Скорость обучения
alpha = 0.01
# Максимальное количество итераций
max_iter = 1000
# Выполнение градиентного спуска для поиска оптимальных значений
x_optimized = gradient_descent(alpha, max_iter)

# Вывод оптимальных значений
print(f"Оптимальное значение x1: {x_optimized[0]}, x2: {x_optimized[1]}")
