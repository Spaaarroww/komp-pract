import math

def series_sum(x, tolerance):
    sum = 0.0
    k = 1

    while True:
        term = (-1) ** k / (math.sin(k * x) + 4 + k ** 2)
        sum += term
        if abs(term) < tolerance:
            break
        k += 1

    return sum

if __name__ == "__main__":
    x = float(input("Введите значение x: "))
    tolerance = 1e-6

    result = series_sum(x, tolerance)
    print("Сумма ряда:", result)
