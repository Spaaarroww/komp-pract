import random
import math

# Класс для представления точки
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Класс для представления параболы в виде y = ax^2 + bx + c
class Parabola:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
    
    # Проверка принадлежности точки параболе
    def is_point_on_parabola(self, p):
        return math.isclose(p.y, self.a * p.x * p.x + self.b * p.x + self.c, rel_tol=1e-9)
    
    # Нахождение координаты фокуса параболы
    def focus(self):
        x_focus = -self.b / (2 * self.a)
        y_focus = (1 - (self.b * self.b - 4 * self.a * self.c)) / (4 * self.a)
        return Point(x_focus, y_focus)
    
    # Нахождение расстояния от директрисы до фокуса
    def distance_from_directrix_to_focus(self):
        return 1 / (4 * self.a)

# Пример данных
a = random.uniform(-10, 10)
b = random.uniform(-10, 10)
c = random.uniform(-10, 10)
x = random.uniform(-10, 10)
y = random.uniform(-10, 10)

parabola = Parabola(a, b, c)
point = Point(x, y)

# Проверка принадлежности точки параболе
if parabola.is_point_on_parabola(point):
    print("Точка принадлежит параболе.")
else:
    print("Точка не принадлежит параболе.")

# Нахождение координаты фокуса параболы
focus = parabola.focus()
print(f"Координаты фокуса параболы: ({focus.x:.2f}, {focus.y:.2f})")

# Нахождение расстояния от директрисы до фокуса
distance = parabola.distance_from_directrix_to_focus()
print(f"Расстояние от директрисы до фокуса: {distance:.2f}")

