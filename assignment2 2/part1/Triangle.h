#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

/**
 * Triangle ADT
 * Stores three sides (double) and exposes analysis utilities.
 * All mutating operations validate the Triangle Inequality.
 *
 * Big‑O notes:
 *  - Accessors/mutators: O(1)
 *  - computeArea / computePerimeter / property checks: O(1)
 */
class Triangle {
private:
    double side1_;
    double side2_;
    double side3_;

    static bool isValidTriple(double a, double b, double c); // O(1)

public:
    // Constructors
    Triangle();                                    // O(1)
    Triangle(double a, double b, double c);        // O(1)

    // Accessors
    double side1() const { return side1_; }        // O(1)
    double side2() const { return side2_; }        // O(1)
    double side3() const { return side3_; }        // O(1)

    // Mutators (return false if invalid and do NOT change the object)
    bool setSide1(double v);                       // O(1)
    bool setSide2(double v);                       // O(1)
    bool setSide3(double v);                       // O(1)

    // Analysis
    double computeArea() const;                    // O(1)
    double computePerimeter() const;               // O(1)
    bool isRightTriangle() const;                  // O(1)
    bool isEquilateralTriangle() const;            // O(1)
    bool isIsoscelesTriangle() const;              // O(1)
};

#endif // TRIANGLE_H
