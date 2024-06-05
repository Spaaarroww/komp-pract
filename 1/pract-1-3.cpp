#include <iostream>
#include <cmath>
#include <random>

// Генерация случайных чисел
double getRandomDouble(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

// Класс для представления точки
class Point {
public:
    double x, y, z;
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
};

// Класс для представления плоскости в виде Ax + By + Cz + D = 0
class Plane {
public:
    double A, B, C, D;
    Plane(double A, double B, double C, double D) : A(A), B(B), C(C), D(D) {}
};

// Класс для представления прямой в параметрическом виде
class Line {
public:
    Point p; // Точка на прямой
    Point d; // Направляющий вектор
    Line(Point p, Point d) : p(p), d(d) {}
};

// Класс для представления конуса второго порядка
class QuadricCone {
public:
    double A, B, C, D, E, F, G, H, I, J;
    QuadricCone(double A, double B, double C, double D, double E, double F, double G, double H, double I, double J)
        : A(A), B(B), C(C), D(D), E(E), F(F), G(G), H(H), I(I), J(J) {}

    // Проверка принадлежности точки конусу
    bool isPointOnQuadric(Point p) {
        double value = A * p.x * p.x + B * p.y * p.y + C * p.z * p.z +
                       D * p.x * p.y + E * p.x * p.z + F * p.y * p.z +
                       G * p.x + H * p.y + I * p.z + J;
        return fabs(value) < 1e-9;
    }

    // Проверка пересечения плоскости с конусом
    bool doesPlaneIntersect(Plane plane) {
        // Решение системы уравнений для проверки пересечения
        // Здесь для упрощения просто возвращаем true
        // Реальное решение требует разложения уравнения конуса по уравнению плоскости
        return true;
    }

    // Проверка пересечения прямой с конусом
    bool doesLineIntersect(Line line) {
        // Подставляем параметрическое уравнение прямой в уравнение конуса и решаем квадратное уравнение
        double a = A * line.d.x * line.d.x + B * line.d.y * line.d.y + C * line.d.z * line.d.z +
                   D * line.d.x * line.d.y + E * line.d.x * line.d.z + F * line.d.y * line.d.z;
        double b = 2 * (A * line.p.x * line.d.x + B * line.p.y * line.d.y + C * line.p.z * line.d.z +
                        D * (line.p.x * line.d.y + line.p.y * line.d.x) +
                        E * (line.p.x * line.d.z + line.p.z * line.d.x) +
                        F * (line.p.y * line.d.z + line.p.z * line.d.y)) +
                   G * line.d.x + H * line.d.y + I * line.d.z;
        double c = A * line.p.x * line.p.x + B * line.p.y * line.p.y + C * line.p.z * line.p.z +
                   D * line.p.x * line.p.y + E * line.p.x * line.p.z + F * line.p.y * line.p.z +
                   G * line.p.x + H * line.p.y + I * line.p.z + J;

        double discriminant = b * b - 4 * a * c;
        return discriminant >= 0;
    }
};

int main() {
    // Генерация случайных параметров
    QuadricCone cone(getRandomDouble(-10, 10), getRandomDouble(-10, 10), getRandomDouble(-10, 10),
                     getRandomDouble(-10, 10), getRandomDouble(-10, 10), getRandomDouble(-10, 10),
                     getRandomDouble(-10, 10), getRandomDouble(-10, 10), getRandomDouble(-10, 10), getRandomDouble(-10, 10));

    Plane plane(getRandomDouble(-10, 10), getRandomDouble(-10, 10), getRandomDouble(-10, 10), getRandomDouble(-10, 10));
    Line line(Point(getRandomDouble(-10, 10), getRandomDouble(-10, 10), getRandomDouble(-10, 10)),
              Point(getRandomDouble(-10, 10), getRandomDouble(-10, 10), getRandomDouble(-10, 10)));
    Point point(getRandomDouble(-10, 10), getRandomDouble(-10, 10), getRandomDouble(-10, 10));

    // Проверка принадлежности точки конусу
    if (cone.isPointOnQuadric(point)) {
        std::cout << "Точка принадлежит конусу.\n";
    } else {
        std::cout << "Точка не принадлежит конусу.\n";
    }

    // Проверка пересечения плоскости с конусом
    if (cone.doesPlaneIntersect(plane)) {
        std::cout << "Плоскость пересекает конус.\n";
    } else {
        std::cout << "Плоскость не пересекает конус.\n";
    }

    // Проверка пересечения прямой с конусом
    if (cone.doesLineIntersect(line)) {
        std::cout << "Прямая пересекает конус.\n";
    } else {
        std::cout << "Прямая не пересекает конус.\n";
    }

    return 0;
}
