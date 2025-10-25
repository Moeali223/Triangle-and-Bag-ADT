#include "Triangle.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

static bool parseTriple(const std::string& s, double& a, double& b, double& c) {
    // Accept formats like "3,4,5" or "3.0, 4.0, 5.0"
    std::stringstream ss(s);
    char comma1, comma2;
    if (ss >> a >> comma1 >> b >> comma2 >> c) {
        return true;
    }
    return false;
}

int main() {
    std::cout << "Enter the sides of a triangle in cms:\n";
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cerr << "No input provided.\n";
        return 1;
    }

    double a, b, c;
    if (!parseTriple(line, a, b, c)) {
        std::cerr << "Invalid input format. Expected: a,b,c\n";
        return 1;
    }

    Triangle t;
    try {
        t = Triangle(a, b, c);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid triangle: " << e.what() << "\n";
        return 1;
    }

    std::cout << "Enter the operation you need to perform:\n";
    std::string op;
    if (!std::getline(std::cin, op)) {
        std::cerr << "No operation provided.\n";
        return 1;
    }

    // Normalize op
    for (auto& ch : op) ch = std::tolower(ch);

    if (op == "area") {
        double area = t.computeArea();
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "The area is " << area << " cm^2\n";
    } else if (op == "perimeter" || op == "peri") {
        double p = t.computePerimeter();
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "The perimeter is " << p << " cm\n";
    } else if (op == "right") {
        std::cout << (t.isRightTriangle() ? "true\n" : "false\n");
    } else if (op == "equilateral" || op == "equi") {
        std::cout << (t.isEquilateralTriangle() ? "true\n" : "false\n");
    } else if (op == "isosceles" || op == "iso") {
        std::cout << (t.isIsoscelesTriangle() ? "true\n" : "false\n");
    } else {
        std::cerr << "Unknown operation. Use one of: area, perimeter, right, equilateral, isosceles\n";
        return 1;
    }

    return 0;
}
