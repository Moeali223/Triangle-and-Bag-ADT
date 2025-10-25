#include "Triangle.h"
#include <cmath>
#include <iostream>
#include <iomanip>

namespace {
    constexpr double EPS = 1e-9;
}

bool Triangle::isValidTriple(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    // Triangle inequality: sum of any two > third
    return (a + b > c + EPS) && (a + c > b + EPS) && (b + c > a + EPS);
}

Triangle::Triangle() : side1_(3.0), side2_(4.0), side3_(5.0) {
    // Default to a valid 3-4-5 triangle
}

Triangle::Triangle(double a, double b, double c) {
    if (!isValidTriple(a, b, c)) {
        throw std::invalid_argument("Invalid triangle sides (violate triangle inequality).");
    }
    side1_ = a; side2_ = b; side3_ = c;
}

bool Triangle::setSide1(double v) {
    if (isValidTriple(v, side2_, side3_)) { side1_ = v; return true; }
    return false;
}
bool Triangle::setSide2(double v) {
    if (isValidTriple(side1_, v, side3_)) { side2_ = v; return true; }
    return false;
}
bool Triangle::setSide3(double v) {
    if (isValidTriple(side1_, side2_, v)) { side3_ = v; return true; }
    return false;
}

double Triangle::computeArea() const {
    // Heron's formula
    double s = computePerimeter() / 2.0;
    double area2 = s * (s - side1_) * (s - side2_) * (s - side3_);
    if (area2 < 0) return 0.0; // numerical guard
    return std::sqrt(area2);
}

double Triangle::computePerimeter() const {
    return side1_ + side2_ + side3_;
}

bool Triangle::isRightTriangle() const {
    // Use Pythagoras with tolerance
    double a = side1_, b = side2_, c = side3_;
    // sort a <= b <= c without std::sort to avoid header—manual compare O(1)
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);
    return std::fabs(a*a + b*b - c*c) <= 1e-6;
}

bool Triangle::isEquilateralTriangle() const {
    return std::fabs(side1_ - side2_) <= 1e-9 &&
           std::fabs(side2_ - side3_) <= 1e-9;
}

bool Triangle::isIsoscelesTriangle() const {
    return std::fabs(side1_ - side2_) <= 1e-9 ||
           std::fabs(side1_ - side3_) <= 1e-9 ||
           std::fabs(side2_ - side3_) <= 1e-9;
}
