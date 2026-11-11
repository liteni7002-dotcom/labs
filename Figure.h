#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Figure {
public:
    Figure();
    virtual ~Figure();

    virtual double CalcArea() = 0;
    virtual void show() = 0;
};

class Circle : public Figure {
private:
    double* radius;
public:
    Circle();
    Circle(double r);
    ~Circle() override;

    double CalcArea() override;
    void show() override;
};

class Rectangle : public Figure {
private:
    double* width;
    double* height;
public:
    Rectangle();
    Rectangle(double w, double h);
    ~Rectangle() override;

    double CalcArea() override;
    void show() override;
};

class Triangle : public Figure {
private:
    double* a;
    double* b;
    double* c;
public:
    Triangle();
    Triangle(double sideA, double sideB, double sideC);
    ~Triangle() override;

    double CalcArea() override;
    void show() override;
};