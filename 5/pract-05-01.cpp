#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Структура для хранения точек
struct Point {
    double x, y;
};

// Структура для хранения коэффициентов сплайна
struct SplineCoefficients {
    vector<double> a, b, c, d;
};

// Функция для вычисления коэффициентов кубического сплайна
SplineCoefficients computeSplineCoefficients(const vector<Point>& points) {
    int n = points.size() - 1;
    vector<double> h(n), alpha(n), l(n + 1), mu(n + 1), z(n + 1);
    SplineCoefficients coeffs;

    // Инициализация векторов a, b, c, d
    coeffs.a.resize(n + 1);
    coeffs.b.resize(n);
    coeffs.c.resize(n + 1);
    coeffs.d.resize(n);

    // Заполнение вектора h
    for (int i = 0; i < n; ++i) {
        h[i] = points[i + 1].x - points[i].x;
        coeffs.a[i] = points[i].y;
    }
    coeffs.a[n] = points[n].y;

    // Заполнение вектора alpha
    for (int i = 1; i < n; ++i) {
        alpha[i] = (3.0 / h[i]) * (coeffs.a[i + 1] - coeffs.a[i]) - (3.0 / h[i - 1]) * (coeffs.a[i] - coeffs.a[i - 1]);
    }

    // Инициализация l, mu, z
    l[0] = 1.0;
    mu[0] = 0.0;
    z[0] = 0.0;

    // Вычисление l, mu, z
    for (int i = 1; i < n; ++i) {
        l[i] = 2.0 * (points[i + 1].x - points[i - 1].x) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n] = 1.0;
    z[n] = 0.0;
    coeffs.c[n] = 0.0;

    // Вычисление коэффициентов b, c, d
    for (int j = n - 1; j >= 0; --j) {
        coeffs.c[j] = z[j] - mu[j] * coeffs.c[j + 1];
        coeffs.b[j] = (coeffs.a[j + 1] - coeffs.a[j]) / h[j] - h[j] * (coeffs.c[j + 1] + 2.0 * coeffs.c[j]) / 3.0;
        coeffs.d[j] = (coeffs.c[j + 1] - coeffs.c[j]) / (3.0 * h[j]);
    }

    return coeffs;
}

// Функция для вычисления значения функции в точке x^* с использованием кубического сплайна
double evaluateSpline(const vector<Point>& points, const SplineCoefficients& coeffs, double x) {
    int n = points.size() - 1;
    int i = n - 1;
    // Поиск соответствующего интервала
    while (i > 0 && x < points[i].x) {
        --i;
    }
    double dx = x - points[i].x;
    // Вычисление значения функции
    return coeffs.a[i] + coeffs.b[i] * dx + coeffs.c[i] * dx * dx + coeffs.d[i] * dx * dx * dx;
}

int main() {
    // Заданные точки интерполяции
    vector<Point> points = {{0.0, 0.0}, {1.0, 0.0}, {2.0, 0.5}, {3.0, 2.0}, {4.0, 0.86603}};
    double x_star = 1.5;

    // Вычисление коэффициентов сплайна
    SplineCoefficients coeffs = computeSplineCoefficients(points);
    // Вычисление значения функции в точке x_star
    double result = evaluateSpline(points, coeffs, x_star);

    // Вывод результата
    cout << "The value of the function at x = " << x_star << " is " << result << endl;
    return 0;
}
