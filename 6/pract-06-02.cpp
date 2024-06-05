#include <iostream>
#include <cmath>
using namespace std;

// Определение функции f(x1, x2)
double f(double x1, double x2) {
    return 7*x1*x1 + 2*x1*x2 + 5*x2*x2 + x1 - 10*x2;
}

// Вычисление градиента функции f в точке (x1, x2)
void gradient(double x1, double x2, double& grad_x1, double& grad_x2) {
    grad_x1 = 14*x1 + 2*x2 + 1;
    grad_x2 = 10*x2 + 2*x1 - 10;
}

// Реализация метода градиентного спуска
void gradient_descent(double& x1, double& x2, double alpha, int max_iter) {
    for (int i = 0; i < max_iter; ++i) {
        double grad_x1, grad_x2;
        // Вычисление градиента в текущей точке
        gradient(x1, x2, grad_x1, grad_x2);
        
        // Обновление значений x1 и x2
        x1 = x1 - alpha * grad_x1;
        x2 = x2 - alpha * grad_x2;

        // Вывод текущей итерации, значений x1 и x2 и значения функции
        cout << "Итерация " << i+1 << ": x1 = " << x1 << ", x2 = " << x2 << ", f(x1, x2) = " << f(x1, x2) << endl;

        // Проверка на сходимость
        if (sqrt(grad_x1*grad_x1 + grad_x2*grad_x2) < 1e-6) break;
    }
}

int main() {
    // Начальные значения x1 и x2
    double x1 = 0.0, x2 = 0.0;
    // Скорость обучения
    double alpha = 0.01;
    // Максимальное количество итераций
    int max_iter = 1000;
    
    // Выполнение градиентного спуска для поиска оптимальных значений
    gradient_descent(x1, x2, alpha, max_iter);
    
    // Вывод оптимальных значений
    cout << "Оптимальное значение x1: " << x1 << ", x2: " << x2 << endl;
    return 0;
}
