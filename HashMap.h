#ifndef HASH_MAP_H
#define HASH_MAP_H
#include "LinkedList.h"

template<typename K ,typename V>
class HashMap {
    struct Pair {
        Pair(K key, const V& value): key(key), value(value) {};
        K key;
        V value;
    };
public:
    HashMap(size_t n = 0);

    ~HashMap();
    HashMap(const HashMap& map);
    HashMap& operator=(const HashMap& map);

    void print() const;
    bool contains(const V& value) const;
    T* search(K key) const;
    int count(K key) const;

    bool insert(K key, const V& value);
    void insert_or_assign(K key, V& value);
    bool erase(K key);

private:
    LinkedList<Pair>* buckets_ = nullptr;
    size_t size_ = 0;
};

#endif /* HASH_MAP_H */