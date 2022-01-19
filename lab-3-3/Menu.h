#include <iostream>
using namespace std;

void printHorizontalLine() {
    cout << "-----------------------------------";
    cout << endl;
}

void printCompaniesMenu() {
    printHorizontalLine();
    cout << "Command action:" << endl;
    cout << "   1.   See the list of companies" << endl;
    cout << "   2.   Load from file" << endl;
    cout << "   3.   Save to file" << endl;
    cout << "   4.   Add company" << endl;
    cout << "   5.   Remove company" << endl;
    cout << "   0.   Exit" << endl;
    printHorizontalLine();
    cout << "Press a number: ";
}

