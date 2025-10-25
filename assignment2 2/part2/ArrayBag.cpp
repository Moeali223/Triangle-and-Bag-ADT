#include "ArrayBag.h"
#include <unordered_map>

bool ArrayBag::add(int item) {
    items_.push_back(item);
    return true;
}

int ArrayBag::size() const {
    return static_cast<int>(items_.size());
}

std::vector<int> ArrayBag::toVector() const {
    return items_;
}

ArrayBag ArrayBag::computeUnion(const ArrayBag& other) const {
    ArrayBag result;
    result.items_ = items_; // copy all from this
    // then append all from other
    result.items_.insert(result.items_.end(), other.items_.begin(), other.items_.end());
    return result;
}

ArrayBag ArrayBag::computeIntersection(const ArrayBag& other) const {
    ArrayBag result;
    std::unordered_map<int, int> freq; // value -> count in this
    for (int v : items_) ++freq[v];
    for (int w : other.items_) {
        auto it = freq.find(w);
        if (it != freq.end() && it->second > 0) {
            result.items_.push_back(w);
            --(it->second);
        }
    }
    return result;
}

ArrayBag ArrayBag::computeDifference(const ArrayBag& other) const {
    ArrayBag result;
    std::unordered_map<int, int> freqOther;
    for (int w : other.items_) ++freqOther[w];
    for (int v : items_) {
        auto it = freqOther.find(v);
        if (it == freqOther.end() || it->second == 0) {
            result.items_.push_back(v);
        } else {
            --(it->second); // consume one
        }
    }
    return result;
}

ArrayBag ArrayBag::computeSymmetricDifference(const ArrayBag& other) const {
    // Elements present in exactly one bag
    std::unordered_map<int, int> a, b;
    for (int v : items_) ++a[v];
    for (int w : other.items_) ++b[w];
    ArrayBag result;
    // For each key in either map, append |countA - countB| copies
    std::unordered_map<int, int> seen = a;
    for (const auto& kv : b) seen[kv.first] += 0; // ensure key exists
    for (const auto& kv : seen) {
        int key = kv.first;
        int ca = a.count(key) ? a[key] : 0;
        int cb = b.count(key) ? b[key] : 0;
        int times = std::abs(ca - cb);
        for (int i = 0; i < times; ++i) result.add(key);
    }
    return result;
}
