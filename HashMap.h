#ifndef HASH_MAP_H
#define HASH_MAP_H
#include "LinkedList.h"
#include <iostream>

template<typename K ,typename V>
struct Pair {
        Pair(K key, const V& value): key(key), value(value) {};
        bool operator==(const Pair& other) const { return key == other.key && value == other.value; }
        K key = K();
        V value = V();
};

template<typename K ,typename V>
std::ostream& operator<<(std::ostream& os, const Pair<K, V>& p) {
        os << "{ " << p.key << " : " << p.value << " }";
        return os;
}

template<typename K ,typename V>
class HashMap {
friend std::ostream& operator<<<K, V>(std::ostream& os, const HashMap& map);
public:
    HashMap(size_t m = 0) {
        if (m > 0) {
            buckets_ = new LinkedList<Pair<K, V>>[m];
            m_ = m;
        }
    }

    ~HashMap() {
        delete[] buckets_;
    }

    HashMap(const HashMap& map) {
        this->buckets_ = new LinkedList<Pair<K, V>>[map.m_];
        this->size_ = map.size_;
        this->m_ = map.m_;
        for (size_t i = 0; i < map.m_; i++) {
            buckets_[i] = map.buckets_[i];
        }
    }

    HashMap& operator=(const HashMap& map) {
        if (&map != this) {
            delete[] this->buckets_;
            this->buckets_ = new LinkedList<Pair<K, V>>[map.m_];
            this->size_ = map.size_;
            this->m_ = map.m_;
            for (size_t i = 0; i < map.m_; i++) {
                buckets_[i] = map.buckets_[i];
            }
        }
        return *this;
    }

    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    void print() const {
        for (size_t i = 0; i < m_; i++) {
            std::cout << buckets_[i] << "\n";
        }
    }
    // bool contains(const V& value) const {}
    // V& search(K key) const;
    // int count(K key) const;

    bool insert(K key, const V& value) {
        size_t idx = hash_(key);
        Pair p = Pair(key, value);

        auto it = buckets_[idx].iterator();
        while (it.has_next()) {
            if (it.next().key == p.key) return false;
        }
        buckets_[idx].push_tail(p);
        return true;
    }

    bool erase(K key) {
        size_t idx = hash_(key);

        auto it = buckets_[idx].iterator();
        while (it.has_next()) {
            Pair p = it.next();
            if (p.key == key) {
                buckets_[idx].delete_node(p);
                return true;
            }
        }
        return false;
    }

    // void insert_or_assign(K key, V& value);
private:
    LinkedList<Pair<K, V>>* buckets_ = nullptr;
    size_t m_ = 0;
    size_t size_ = 0;

    size_t hash_(K key) const {
        return key % m_;
    }
};

template<typename K ,typename V>
std::ostream& operator<<(std::ostream& os, const HashMap<K, V>& map) {
    for (size_t i = 0; i < map.m_; i++) {
        os << map.buckets_[i] << "\n";
    }
    return os;
}

#endif /* HASH_MAP_H */