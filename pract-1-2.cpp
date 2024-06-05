#include <iostream>
#include <cmath>

// Класс для представления точки
class Point {
public:
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

// Класс для представления параболы в виде y = ax^2 + bx + c
class Parabola {
public:
    double a, b, c;
    Parabola(double a, double b, double c) : a(a), b(b), c(c) {}
    
    // Проверка принадлежности точки параболе
    bool isPointOnParabola(Point p) {
        return p.y == a * p.x * p.x + b * p.x + c;
    }
    
    // Нахождение координаты фокуса параболы
    Point focus() {
        double x_focus = -b / (2 * a);
        double y_focus = (1 - (b * b - 4 * a * c)) / (4 * a);
        return Point(x_focus, y_focus);
    }
    
    // Нахождение расстояния от директрисы до фокуса
    double distanceFromDirectrixToFocus() {
        return 1 / (4 * a);
    }
};

int main() {
    // Пример данных
    Parabola parabola(1, -3, 2);  // Парабола: y = x^2 - 3x + 2
    Point point(1, 0);  // Точка (1, 0)
    
    // Проверка принадлежности точки параболе
    if (parabola.isPointOnParabola(point)) {
        std::cout << "Точка принадлежит параболе.\n";
    } else {
        std::cout << "Точка не принадлежит параболе.\n";
    }
    
    // Нахождение координаты фокуса параболы
    Point focus = parabola.focus();
    std::cout << "Координаты фокуса параболы: (" << focus.x << ", " << focus.y << ")\n";
    
    // Нахождение расстояния от директрисы до фокуса
    double distance = parabola.distanceFromDirectrixToFocus();
    std::cout << "Расстояние от директрисы до фокуса: " << distance << "\n";
    
    return 0;
}
