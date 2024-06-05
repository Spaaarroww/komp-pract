import math

# Класс для представления точки
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Класс для представления прямой в виде Ax + By + C = 0
class Line:
    def __init__(self, A, B, C):
        self.A = A
        self.B = B
        self.C = C

# Функция для нахождения расстояния от точки до прямой
def distance_point_to_line(p, l):
    return abs(l.A * p.x + l.B * p.y + l.C) / math.sqrt(l.A ** 2 + l.B ** 2)

# Функция для нахождения точки пересечения двух прямых
def intersection_point(l1, l2):
    det = l1.A * l2.B - l2.A * l1.B
    if det == 0:
        print("Прямые параллельны или совпадают")
        return Point(float('nan'), float('nan'))
    else:
        x = (l2.B * l1.C - l1.B * l2.C) / det
        y = (l1.A * l2.C - l2.A * l1.C) / det
        return Point(x, y)

# Функция для нахождения расстояния между двумя точками
def distance_between_points(p1, p2):
    return math.sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)

# Функция для нахождения угла между двумя прямыми
def angle_between_lines(l1, l2):
    dot_product = l1.A * l2.A + l1.B * l2.B
    magnitude1 = math.sqrt(l1.A ** 2 + l1.B ** 2)
    magnitude2 = math.sqrt(l2.A ** 2 + l2.B ** 2)
    return math.acos(dot_product / (magnitude1 * magnitude2)) * 180.0 / math.pi

# Пример данных
l1 = Line(1, -1, 0)  # Прямая 1: x - y = 0
l2 = Line(1, 2, -5)  # Прямая 2: x + 2y - 5 = 0
p = Point(3, 2)  # Точка (3, 2)

# Нахождение расстояния от точки до прямых
dist_to_l1 = distance_point_to_line(p, l1)
dist_to_l2 = distance_point_to_line(p, l2)

# Нахождение точки пересечения прямых
intersection = intersection_point(l1, l2)

# Нахождение расстояния от точки до точки пересечения прямых
dist_to_intersection = distance_between_points(p, intersection)

# Нахождение угла между прямыми
angle = angle_between_lines(l1, l2)

# Вывод результатов
print(f"Расстояние от точки до прямой 1: {dist_to_l1:.2f}")
print(f"Расстояние от точки до прямой 2: {dist_to_l2:.2f}")
print(f"Точка пересечения прямых: ({intersection.x:.2f}, {intersection.y:.2f})")
print(f"Расстояние от точки до точки пересечения прямых: {dist_to_intersection:.2f}")
print(f"Угол между прямыми: {angle:.2f} градусов")