//Написать программу которая будет описывать фигуры, выводить их на экран и
//считать периметр фигур  и сколько точек нужно для их построения, использовать ООП и лямда

#include <iostream>
#include <vector>
#include <functional>

// Базовый класс для фигур
class Shape
{
public:
    // Виртуальный метод для расчета периметра
    virtual double perimeter() const = 0;

    // Виртуальный метод для вывода фигуры на экран
    virtual void draw() const = 0;

    // Виртуальный метод для получения количества точек для построения фигуры
    virtual int numPoints() const = 0;
};

// Класс для круга
class Circle : public Shape
{
public:
    Circle(double r) : radius(r) {}

    double perimeter() const override
    {
        return 2 * 3.14 * radius;
    }

    void draw() const override
    {
        std::cout << "О" << std::endl;
    }

    int numPoints() const override
    {
        return 1;
    }

private:
    double radius;
};

// Класс для квадрата
class Square : public Shape
{
public:
    Square(double s) : side(s) {}

    double perimeter() const override
    {
        return 4 * side;
    }

    void draw() const override
    {
        std::cout << "+---+" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "+---+" << std::endl;
    }

    int numPoints() const override
    {
        return 4;
    }

private:
    double side;
};

// Класс для прямоугольника
class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double perimeter() const override
    {
        return 2 * (width + height);
    }

    void draw() const override
    {
        std::cout << "+";
        for (int i = 0; i < width; i++)
        {
            std::cout << "-";
        }
        std::cout << "+" << std::endl;

        for (int i = 0; i < height; i++)
        {
            std::cout << "|";
            for (int j = 0; j < width; j++)
            {
                std::cout << " ";
            }
            std::cout << "|" << std::endl;
        }

        std::cout << "+";
        for (int i = 0; i < width; i++)
        {
            std::cout << "-";
        }
        std::cout << "+" << std::endl;
    }

    int numPoints() const override
    {
        return 4;
    }

private:
    double width;
    double height;
};

int main()
{
    setlocale(LC_ALL, "ru");
    // Создаем вектор объектов класса Shape
    std::vector<std::unique_ptr<Shape>> shapes;

    // Добавляем несколько фигур в вектор
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Square>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    // Выводим на экран каждую фигуру и ее периметр
    for (const auto& shape : shapes)
    {
        std::cout << "Фигура: "<< std::endl;
        shape->draw();
        std::cout << "Периметр: " << shape->perimeter() << std::endl;
        std::cout << "Точек для построения: " << shape->numPoints() << std::endl;
        std::cout << std::endl;
    }

    // Используем лямбда-функцию для подсчета общего периметра
    double totalPerimeter = 0.0;
    for (const auto& shape : shapes)
    {
        totalPerimeter += shape->perimeter();
    }

    std::cout << "Общий периметр: " << totalPerimeter << std::endl;

    return 0;
}