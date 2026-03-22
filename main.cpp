#include <iostream>
#include "HashMap.h"
#include <random>
#include <set>

bool has_collision(const HashMap<int, int>& map, const std::set<int>& keys) {
    for (int key: keys) {
        if (map.count(key) > 0) return true;
    }
    return false;
}

double collision_statistic(size_t m, size_t n) {
    std::mt19937 rand(42);
    double collision = 0;
    for (size_t i = 0; i < 100; i++) {
        HashMap<int, int> map(m);
        std::set<int> keys;
        int key = 0;
        for (size_t j = 0; j < n; j++) {
            key = rand();
            keys.insert(key);
            map.insert(key, rand());
        }
        collision += (double) has_collision(map, keys) / (double) 100;
    }
    return collision;
}

int main() {
    double result = 0;
    for (size_t i = 25; i < 475; i += 50) {
        result = collision_statistic(i, 25);
        std::cout << "size: " << i << " collision: " << result << "\n";
    }
}