#include "ArrayBag.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static std::vector<int> parseInts(const std::string& s) {
    std::vector<int> out;
    std::stringstream ss(s);
    while (ss.good()) {
        int val;
        char sep;
        if (ss >> val) {
            out.push_back(val);
            if (ss >> sep) {
                // expect comma or whitespace, ignore
            }
        } else {
            ss.clear();
            std::string junk;
            if (!(ss >> junk)) break;
        }
    }
    return out;
}

static void printBag(const ArrayBag& b) {
    auto v = b.toVector();
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Enter the contents of bag 1:\n";
    std::string line1;
    if (!std::getline(std::cin, line1)) return 1;
    std::cout << "Enter the contents of bag 2:\n";
    std::string line2;
    if (!std::getline(std::cin, line2)) return 1;

    ArrayBag b1, b2;
    for (int x : parseInts(line1)) b1.add(x);
    for (int y : parseInts(line2)) b2.add(y);

    // Interactive operations until EOF
    // Supported: union, intersect, diff, symdiff
    std::string op;
    while (true) {
        if (!std::getline(std::cin, op)) break;
        for (auto& ch : op) ch = std::tolower(ch);
        if (op == "union") {
            printBag(b1.computeUnion(b2));
        } else if (op == "intersect" || op == "intersection") {
            printBag(b1.computeIntersection(b2));
        } else if (op == "diff" || op == "difference") {
            printBag(b1.computeDifference(b2));
        } else if (op == "symdiff" || op == "symmetric" || op == "symmetric difference") {
            printBag(b1.computeSymmetricDifference(b2));
        } else if (op.empty()) {
            continue;
        } else {
            std::cerr << "Unknown operation. Use: union, intersect, diff, symdiff\n";
        }
    }

    return 0;
}
