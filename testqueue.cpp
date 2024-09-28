#include <iostream>
#include "Queue.h" // Include your Queue header file

int main() {
    // Test queue initialization with size 0
    Queue<int> queue1(0);
    std::cout << "Queue size after initialization (size 0): " << queue1.size() << std::endl;

    // Test queue initialization with size 5
    Queue<int> queue2(5);
    std::cout << "Queue size after initialization (size 5): " << queue2.size() << std::endl;

    return 0;
}