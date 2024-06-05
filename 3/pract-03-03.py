import math

# Функция для вычисления члена ряда
def term(k):
    return 4.0 / (2**(k - 1)) + (-1)**(k - 1) / (2 * 3**(k - 1))

# Главная функция
if __name__ == "__main__":
    epsilon = 1e-6
    sum = 0.0
    k = 1

    while True:
        t = term(k)
        sum += t
        if abs(t) < epsilon:
            break
        k += 1

    print("Sum of the series: {:.6f}".format(sum))
