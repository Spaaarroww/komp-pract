#include <iostream>
#include <cmath>

double series_sum(double x, double tolerance) {
    double sum = 0.0;
    double term;
    int k = 1;

    do {
        term = pow(-1, k) / (sin(k * x) + 4 + k * k);
        sum += term;
        k++;
    } while (fabs(term) > tolerance);

    return sum;
}

int main() {
    double x;
    double tolerance = 1e-6;

    std::cout << "Введите значение x: ";
    std::cin >> x;

    double result = series_sum(x, tolerance);
    std::cout << "Сумма ряда: " << result << std::endl;

    return 0;
}
