#include <iostream>
#include "HashMap.h"

int main() {
    HashMap<int, std::string> map1;

    map1.insert(1, "hello1");
    map1.insert(6, "hello2");
    map1.insert(2, "hello2");
    map1.insert(3, "hello2");
    map1.insert(3, "hello4");
    map1[-1] = "world!";
    map1[6] = "hello world!";
    map1[0] = "none";
    std::cout << map1;
}