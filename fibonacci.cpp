#include <iostream>

void printFibonacci(int n) {
    long long first = 0, second = 1, next;
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        std::cout << next << " ";
    }
    std::cout << std::endl;
}

int main() {
    int terms;
    std::cout << "Enter the number of terms: ";
    std::cin >> terms;
    printFibonacci(terms);
    return 0;
}