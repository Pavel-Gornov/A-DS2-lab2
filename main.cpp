#include <iostream>
#include "HashMap.h"

int main() {
    HashMap<int, std::string> map1(2);

    std::cout << map1.insert(1, "hello1") << "\n";
    std::cout << map1.insert(6, "hello2") << "\n";
    std::cout << map1.insert(2, "hello2") << "\n";
    std::cout << map1.insert(3, "hello2") << "\n";
    std::cout << map1.insert(3, "hello4") << "\n";
    std::cout << map1;

    map1.erase(1); map1.erase(3);

    
    std::cout << map1.insert(1, "hello1") << "\n";
    std::cout << map1.insert(3, "hello2") << "\n";
    std::cout << map1;
}