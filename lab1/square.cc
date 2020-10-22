#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double number;
    double squared;
    std::cout << "Enter a number: ";
    std::cin >> number;
    squared = pow(number, 2);
    std::cout << number << " squared is equal to " << squared;
    return 0;
}
