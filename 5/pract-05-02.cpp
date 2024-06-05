#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Структура для хранения точек
struct Point {
    double x, y;
};

// Функция для вычисления разделенных разностей
vector<double> dividedDifferences(const vector<Point>& points) {
    int n = points.size();
    vector<vector<double>> table(n, vector<double>(n));

    // Заполнение начальных значений (y_i)
    for (int i = 0; i < n; ++i) {
        table[i][0] = points[i].y;
    }

    // Заполнение таблицы разделенных разностей
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (points[i + j].x - points[i].x);
        }
    }

    // Возвращаем верхнюю строку таблицы, содержащую коэффициенты
    vector<double> coefficients(n);
    for (int i = 0; i < n; ++i) {
        coefficients[i] = table[0][i];
    }
    return coefficients;
}

// Функция для вычисления значения интерполяционного многочлена Ньютона в точке x
double newtonPolynomial(const vector<Point>& points, const vector<double>& coefficients, double x) {
    double result = coefficients[0];
    double term = 1.0;

    for (int i = 1; i < coefficients.size(); ++i) {
        term *= (x - points[i - 1].x);
        result += coefficients[i] * term;
    }
    return result;
}

int main() {
    // Заданные точки интерполяции
    vector<Point> points = {
        {0.1 * M_PI, cos(0.1 * M_PI)},
        {0.2 * M_PI, cos(0.2 * M_PI)},
        {0.3 * M_PI, cos(0.3 * M_PI)},
        {0.4 * M_PI, cos(0.4 * M_PI)}
    };

    // Точка, в которой нужно вычислить значение функции
    double x_star = 0.25 * M_PI;

    // Вычисление коэффициентов многочлена Ньютона
    vector<double> coefficients = dividedDifferences(points);

    // Вычисление значения функции в точке x_star
    double interpolated_value = newtonPolynomial(points, coefficients, x_star);
    double exact_value = cos(x_star);
    double error = fabs(interpolated_value - exact_value);

    // Вывод результатов
    cout << "Interpolated value at x = " << x_star << " is " << interpolated_value << endl;
    cout << "Exact value at x = " << x_star << " is " << exact_value << endl;
    cout << "Error is " << error << endl;

    return 0;
}
