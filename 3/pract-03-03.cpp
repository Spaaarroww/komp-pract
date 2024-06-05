#include <iostream>
#include <cmath>

// Функция для вычисления члена ряда
double term(int k) {
    return 4.0 / pow(2, k - 1) + pow(-1, k - 1) / (2 * pow(3, k - 1));
}

// Главная функция
int main() {
    const double epsilon = 1e-6;
    double sum = 0.0;
    int k = 1;

    while (true) {
        double t = term(k);
        sum += t;
        if (std::fabs(t) < epsilon) break;
        ++k;
    }

    std::cout << "Sum of the series: " << sum << std::endl;
    return 0;
}
