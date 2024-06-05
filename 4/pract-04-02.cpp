#include <iostream>
#include <vector>
#include <cmath>

// Функция для вычисления детерминанта матрицы 3x3
double determinant(const std::vector<std::vector<double>>& matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

// Метод Крамера
std::vector<double> cramerMethod(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    double detA = determinant(A);
    if (detA == 0) {
        throw std::runtime_error("Matrix is singular and cannot be solved by Cramer's rule.");
    }

    std::vector<double> x(3);
    for (int i = 0; i < 3; ++i) {
        std::vector<std::vector<double>> Ai = A;
        for (int j = 0; j < 3; ++j) {
            Ai[j][i] = b[j];
        }
        x[i] = determinant(Ai) / detA;
    }
    return x;
}

// Метод Якоби
std::vector<double> jacobiMethod(const std::vector<std::vector<double>>& A, const std::vector<double>& b, int maxIterations = 1000, double tolerance = 1e-10) {
    int n = A.size();
    std::vector<double> x(n, 0.0);
    std::vector<double> x_old(n);

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        x_old = x;
        for (int i = 0; i < n; ++i) {
            double sigma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sigma += A[i][j] * x_old[j];
                }
            }
            x[i] = (b[i] - sigma) / A[i][i];
        }

        // Проверка на сходимость
        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error += std::abs(x[i] - x_old[i]);
        }
        if (error < tolerance) {
            break;
        }
    }
    return x;
}

int main() {
    std::vector<std::vector<double>> A = {
        {5, -2, -1},
        {2, -1, -1},
        {2, -4, -8}
    };
    std::vector<double> b = {0, -1, 1};

    try {
        std::vector<double> x_cramer = cramerMethod(A, b);
        std::cout << "Решение системы методом Крамера:\n";
        for (int i = 0; i < x_cramer.size(); ++i) {
            std::cout << "x" << i + 1 << " = " << x_cramer[i] << "\n";
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << "\n";
    }

    std::vector<double> x_jacobi = jacobiMethod(A, b);
    std::cout << "Решение системы методом Якоби:\n";
    for (int i = 0; i < x_jacobi.size(); ++i) {
        std::cout << "x" << i + 1 << " = " << x_jacobi[i] << "\n";
    }

    return 0;
}
