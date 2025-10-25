#ifndef ARRAYBAG_H
#define ARRAYBAG_H

#include <vector>
#include <string>
#include <unordered_map>

/**
 * Integer-only Bag (multiset semantics).
 * Uses a dynamic array (std::vector<int>) as backing store.
 *
 * Big‑O notes:
 *  - add, size, toVector: O(1) amortized for push_back / O(n) for toVector
 *  - computeUnion: O(n + m)
 *  - computeIntersection: O(n + m) expected (hash map)
 *  - computeDifference: O(n + m) expected
 *  - computeSymmetricDifference: O(n + m) expected
 */
class ArrayBag {
private:
    std::vector<int> items_;

public:
    ArrayBag() = default;

    bool add(int item);                        // O(1) amortized
    int size() const;                          // O(1)
    std::vector<int> toVector() const;         // O(n)

    // Extensions
    ArrayBag computeUnion(const ArrayBag& other) const;               // O(n+m)
    ArrayBag computeIntersection(const ArrayBag& other) const;        // O(n+m)
    ArrayBag computeDifference(const ArrayBag& other) const;          // O(n+m)
    ArrayBag computeSymmetricDifference(const ArrayBag& other) const; // O(n+m)

    // Operator overloading: difference
    ArrayBag operator-(const ArrayBag& other) const {                 // O(n+m)
        return computeDifference(other);
    }
};

#endif // ARRAYBAG_H
