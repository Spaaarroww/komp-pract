#include <iostream>
#include <cmath>
#include <functional>

// Функция, которую нужно интегрировать
double f(double x) {
    return exp(-2 * x) * sin(4 * x);
}

// Метод прямоугольников
double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Метод трапеций
double trapezoidal_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Метод Симпсона
double simpson_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h) * (i % 2 == 0 ? 2 : 4);
    }
    return sum * h / 3.0;
}

// Главная функция
int main() {
    double a = 0.0;
    double b = 10.0; // Достаточно большой предел интегрирования для аппроксимации бесконечности
    int n = 1000000; // Количество шагов

    double rect_result = rectangle_method(a, b, n);
    double trap_result = trapezoidal_method(a, b, n);
    double simp_result = simpson_method(a, b, n);

    std::cout << "Rectangle Method: " << rect_result << std::endl;
    std::cout << "Trapezoidal Method: " << trap_result << std::endl;
    std::cout << "Simpson Method: " << simp_result << std::endl;

    return 0;
}
