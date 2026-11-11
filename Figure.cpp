#define _USE_MATH_DEFINES
#include "Figure.h"
#include <cmath>

using namespace std;

Figure::Figure() { cout << "Figure::Figure()" << endl; }
Figure::~Figure() { cout << "Figure::~Figure()" << endl; }

Circle::Circle() {
    cout << "Circle::Circle()" << endl;
    radius = new double(1.0);
}
Circle::Circle(double r) {
    cout << "Circle::Circle(double r)" << endl;
    if (r <= 0) throw invalid_argument("The radius must be greater than 0");
    radius = new double(r);
}
Circle::~Circle() {
    cout << "Circle::~Circle()" << endl;
    delete radius;
}
double Circle::CalcArea() {
    cout << "Circle::CalcArea()" << endl;
    return M_PI * (*radius) * (*radius);
}
void Circle::show() {
    cout << "Circle::show() " << endl;
    cout << "Figures: Circle; Radius: " << *radius << "; Area: " << CalcArea() << endl;
}

Rectangle::Rectangle() {
    cout << "Rectangle::Rectangle()" << endl;
    width = new double(1.0);
    height = new double(1.0);
}
Rectangle::Rectangle(double w, double h) {
    cout << "Rectangle::Rectangle(double w," << endl;
    if (w <= 0 || h <= 0) throw invalid_argument("The sides must be greater than 0");
    width = new double(w);
    height = new double(h);
}
Rectangle::~Rectangle() {
    cout << "Rectangle::~Rectangle()" << endl;
    delete width;
    delete height;
}
double Rectangle::CalcArea() {
    cout << "Rectangle::CalcArea()" << endl;
    return (*width) * (*height);
}
void Rectangle::show() {
    cout << "Rectangle::show()" << endl;
    cout << "Figures: Rectangle; Width: " << *width << ", Height: " << *height << "; Площадь: " << CalcArea() << endl;
}

Triangle::Triangle() {
    cout << "Triangle::Triangle()" << endl;
    a = new double(3.0);
    b = new double(4.0);
    c = new double(5.0);
}
Triangle::Triangle(double sideA, double sideB, double sideC) {
    cout << "Triangle::Triangle(double sideA" << endl;
    if (sideA <= 0 || sideB <= 0 || sideC <= 0 ||
        (sideA + sideB <= sideC) || (sideA + sideC <= sideB) || (sideB + sideC <= sideA)) {
        throw invalid_argument("Incorrect sides of the triangle");
    }
    a = new double(sideA);
    b = new double(sideB);
    c = new double(sideC);
}
Triangle::~Triangle() {
    cout << "Triangle::~Triangle()" << endl;
    delete a;
    delete b;
    delete c;
}
double Triangle::CalcArea() {
    cout << "Triangle::CalcArea()" << endl;
    double p = (*a + *b + *c) / 2.0;
    return sqrt(p * (p - *a) * (p - *b) * (p - *c));
}
void Triangle::show() {
    cout << "Triangle::show()" << endl;
    cout << "Figures: Triangle; Sides: " << *a << ", " << *b << ", " << *c << "; Area: " << CalcArea() << endl;
}