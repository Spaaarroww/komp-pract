#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Функция f(x)
double f(const vector<double>& x) {
    return x[0] * x[0] + 3 * x[1] * x[1] + cos(x[0] + x[1]);
}

// Производная функции по x1
double df_dx1(const vector<double>& x) {
    return 2 * x[0] - sin(x[0] + x[1]);
}

// Производная функции по x2
double df_dx2(const vector<double>& x) {
    return 6 * x[1] - sin(x[0] + x[1]);
}

// Метод покоординатного спуска
vector<double> coordinateDescent(double learning_rate, int iterations) {
    vector<double> x = {0, 0};  // Начальные значения
    for (int i = 0; i < iterations; ++i) {
        // Обновление x1
        x[0] -= learning_rate * df_dx1(x);
        // Обновление x2
        x[1] -= learning_rate * df_dx2(x);
    }
    return x;
}

int main() {
    double learning_rate = 0.01;
    int iterations = 1000;
    vector<double> result = coordinateDescent(learning_rate, iterations);

    // Вывод результатов
    cout << "Optimal x1: " << result[0] << endl;
    cout << "Optimal x2: " << result[1] << endl;
    cout << "Minimum value of f(x): " << f(result) << endl;

    return 0;
}
