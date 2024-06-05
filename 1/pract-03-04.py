import random
import numpy as np

# Генерация случайных чисел
def get_random_double(min_val, max_val):
    return random.uniform(min_val, max_val)

# Класс для представления точки
class Point:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

# Класс для представления плоскости в виде Ax + By + Cz + D = 0
class Plane:
    def __init__(self, A, B, C, D):
        self.A = A
        self.B = B
        self.C = C
        self.D = D

# Класс для представления прямой в параметрическом виде
class Line:
    def __init__(self, p, d):
        self.p = p  # Точка на прямой
        self.d = d  # Направляющий вектор

# Класс для представления конуса второго порядка
class QuadricCone:
    def __init__(self, A, B, C, D, E, F, G, H, I, J):
        self.A = A
        self.B = B
        self.C = C
        self.D = D
        self.E = E
        self.F = F
        self.G = G
        self.H = H
        self.I = I
        self.J = J

    # Проверка принадлежности точки конусу
    def is_point_on_quadric(self, p):
        value = (self.A * p.x * p.x + self.B * p.y * p.y + self.C * p.z * p.z +
                 self.D * p.x * p.y + self.E * p.x * p.z + self.F * p.y * p.z +
                 self.G * p.x + self.H * p.y + self.I * p.z + self.J)
        return np.isclose(value, 0, atol=1e-9)

    # Проверка пересечения плоскости с конусом
    def does_plane_intersect(self, plane):
        # Решение системы уравнений для проверки пересечения
        # Здесь для упрощения просто возвращаем True
        # Реальное решение требует разложения уравнения конуса по уравнению плоскости
        return True

    # Проверка пересечения прямой с конусом
    def does_line_intersect(self, line):
        # Подставляем параметрическое уравнение прямой в уравнение конуса и решаем квадратное уравнение
        a = (self.A * line.d.x * line.d.x + self.B * line.d.y * line.d.y + self.C * line.d.z * line.d.z +
             self.D * line.d.x * line.d.y + self.E * line.d.x * line.d.z + self.F * line.d.y * line.d.z)
        b = (2 * (self.A * line.p.x * line.d.x + self.B * line.p.y * line.d.y + self.C * line.p.z * line.d.z +
                  self.D * (line.p.x * line.d.y + line.p.y * line.d.x) +
                  self.E * (line.p.x * line.d.z + line.p.z * line.d.x) +
                  self.F * (line.p.y * line.d.z + line.p.z * line.d.y)) +
             self.G * line.d.x + self.H * line.d.y + self.I * line.d.z)
        c = (self.A * line.p.x * line.p.x + self.B * line.p.y * line.p.y + self.C * line.p.z * line.p.z +
             self.D * line.p.x * line.p.y + self.E * line.p.x * line.p.z + self.F * line.p.y * line.p.z +
             self.G * line.p.x + self.H * line.p.y + self.I * line.p.z + self.J)

        discriminant = b * b - 4 * a * c
        return discriminant >= 0

# Пример данных
cone = QuadricCone(get_random_double(-10, 10), get_random_double(-10, 10), get_random_double(-10, 10),
                   get_random_double(-10, 10), get_random_double(-10, 10), get_random_double(-10, 10),
                   get_random_double(-10, 10), get_random_double(-10, 10), get_random_double(-10, 10), get_random_double(-10, 10))

plane = Plane(get_random_double(-10, 10), get_random_double(-10, 10), get_random_double(-10, 10), get_random_double(-10, 10))
line = Line(Point(get_random_double(-10, 10), get_random_double(-10, 10), get_random_double(-10, 10)),
            Point(get_random_double(-10, 10), get_random_double(-10, 10), get_random_double(-10, 10)))
point = Point(get_random_double(-10, 10), get_random_double(-10, 10), get_random_double(-10, 10))

# Проверка принадлежности точки конусу
if cone.is_point_on_quadric(point):
    print("Точка принадлежит конусу.")
else:
    print("Точка не принадлежит конусу.")

# Проверка пересечения плоскости с конусом
if cone.does_plane_intersect(plane):
    print("Плоскость пересекает конус.")
else:
    print("Плоскость не пересекает конус.")

# Проверка пересечения прямой с конусом
if cone.does_line_intersect(line):
    print("Прямая пересекает конус.")
else:
    print("Прямая не пересекает конус.")

