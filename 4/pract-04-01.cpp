#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// Функция для вывода матрицы и вектора
void printSystem(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(10) << A[i][j] << " ";
        }
        std::cout << " | " << std::setw(10) << b[i] << std::endl;
    }
    std::cout << std::endl;
}

// Функция для решения системы уравнений методом Гаусса
void gaussianElimination(std::vector<std::vector<double>>& A, std::vector<double>& b) {
    int n = A.size();
    
    for (int i = 0; i < n; i++) {
        // Частичное осевое упорядочивание
        for (int k = i + 1; k < n; k++) {
            if (std::abs(A[i][i]) < std::abs(A[k][i])) {
                std::swap(A[i], A[k]);
                std::swap(b[i], b[k]);
            }
        }
        
        // Процесс исключения
        for (int k = i + 1; k < n; k++) {
            double t = A[k][i] / A[i][i];
            for (int j = 0; j < n; j++) {
                A[k][j] -= t * A[i][j];
            }
            b[k] -= t * b[i];
        }
    }
    
    // Обратная подстановка
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    std::cout << "Решение системы методом Гаусса:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "x" << i + 1 << " = " << x[i] << std::endl;
    }
}

// Функция для решения системы уравнений матричным методом (обратная матрица)
std::vector<double> matrixMethod(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    int n = A.size();
    std::vector<std::vector<double>> invA(n, std::vector<double>(n, 0.0));
    std::vector<std::vector<double>> augmentedA(n, std::vector<double>(2 * n, 0.0));
    
    // Создание расширенной матрицы (A | I)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmentedA[i][j] = A[i][j];
        }
        augmentedA[i][i + n] = 1.0;
    }
    
    // Приведение расширенной матрицы к ступенчатому виду
    for (int i = 0; i < n; i++) {
        double diagElement = augmentedA[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmentedA[i][j] /= diagElement;
        }
        for (int k = 0; k < n; k++) {
            if (i != k) {
                double factor = augmentedA[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmentedA[k][j] -= factor * augmentedA[i][j];
                }
            }
        }
    }
    
    // Извлечение обратной матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            invA[i][j] = augmentedA[i][j + n];
        }
    }
    
    // Умножение обратной матрицы на вектор b для получения решения
    std::vector<double> x(n, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i] += invA[i][j] * b[j];
        }
    }
    
    return x;
}

int main() {
    // Матрица A и вектор b для метода Гаусса
    std::vector<std::vector<double>> A = {
        {7, -5, 6, 7},
        {8, -1, -9, 1},
        {-3, 8, 8, 8},
        {2, -3, 6, -4}
    };
    
    std::vector<double> b = {120, 31, 6, 25};
    
    // Решение методом Гаусса
    std::vector<std::vector<double>> A_copy = A;
    std::vector<double> b_copy = b;
    gaussianElimination(A_copy, b_copy);

    // Решение матричным методом
    std::vector<double> x_matrix = matrixMethod(A, b);

    std::cout << "Решение системы матричным методом:\n";
    for (int i = 0; i < x_matrix.size(); i++) {
        std::cout << "x" << i + 1 << " = " << x_matrix[i] << std::endl;
    }

    return 0;
}
