#include <iostream>
#include <cmath>

class Triangle {
private:
    double a, b, c; 

public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}

    double getA() const {return a;}
    double getB() const {return b;}
    double getC() const {return c;}

    double perimeter() const {
        return a + b + c;
    }

    double area() const {
        double p = perimeter() / 2;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Square {
private:
    double side; 

public:
    Square(double sideLength) : side(sideLength) {}

    double getSide() const {return side;}

    double perimeter() const {
        return 4 * side;
    }

    double area() const {
        return std::pow(side, 2);
    }
};

class Circle {
private:
    double radius;
    static constexpr double PI = 3.141592653589793; 

public:
    Circle(double radiusValue) : radius(radiusValue) {}

    double getRadius() const {return radius;}

    double perimeter() const {
        return 2 * PI * radius;
    }

    double area() const {
        return PI * std::pow(radius, 2);
    }
};

int main() {
    Triangle t(3, 4, 5);
    std::cout << "Triangle 3 4 5 perimeter: " << t.perimeter() << std::endl;
    std::cout << "Triangle area: " << t.area() << std::endl;

    Square s(8);
    std::cout << "Square 8 perimeter: " << s.perimeter() << std::endl;
    std::cout << "Square area: " << s.area() << std::endl;

    Circle c(10);
    std::cout << "Circle 10 perimeter: " << c.perimeter() << std::endl;
    std::cout << "Circle area: " << c.area() << std::endl;

    return EXIT_SUCCESS;
}
