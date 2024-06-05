#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> gaussSeidel(const std::vector<std::vector<double>>& A, const std::vector<double>& b, double tolerance = 0.01, int maxIterations = 1000) {
    int n = A.size();
    std::vector<double> x(n, 0.0); // Начальные приближения
    std::vector<double> x_old(n);

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        x_old = x;

        for (int i = 0; i < n; ++i) {
            double sigma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sigma += A[i][j] * x[j];
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
        {-18, 9, -1, -8},
        {6, 22, 9, 0},
        {-4, 2, -16, 9},
        {1, 6, -1, -14}
    };
    std::vector<double> b = {-60, -109, -103, -33};

    std::vector<double> x = gaussSeidel(A, b);

    std::cout << "Решение системы методом Зейделя:\n";
    for (int i = 0; i < x.size(); ++i) {
        std::cout << "x" << i + 1 << " = " << x[i] << "\n";
    }

    return 0;
}
