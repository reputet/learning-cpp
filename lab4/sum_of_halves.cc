#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int number = 0;
    while (number < 1000000) {
        int left_half;
        int right_half;
        int left_sum = 0;
        int right_sum = 0;

        // First three digits including leading zeros
        left_half = number / 1000;
        while (left_half != 0) {
            left_sum += left_half % 10;
            left_half /= 10;
        };

        // Last three digits including leading zeros
        right_half = number % 1000;
        while (right_half != 0) {
            right_sum += right_half % 10;
            right_half /= 10;
        };

        if (left_sum == right_sum) {
            std::cout << std::setfill('0') << std::setw(6) << number << " is a lucky number" << endl;
        }
        number++;
    }
    return 0;
}
