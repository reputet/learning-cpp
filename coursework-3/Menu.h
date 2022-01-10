#include <iostream>
using namespace std;

void printHorizontalLine() {
    cout << "-----------------------------------";
    cout << endl;
}

void printCommonMenu() {
    printHorizontalLine();
    cout << "Command action:" << endl;
    cout << "   1.   Manage candidates" << endl;
    cout << "   2.   Manage companies" << endl;
    cout << "   3.   Manage jobs" << endl;
    cout << "   4.   Match positions automatically" << endl;
    cout << "   0.   Exit" << endl;
    printHorizontalLine();
    cout << "Press a number: ";
}

void printApplicantsMenu() {
    printHorizontalLine();
    cout << "Command action:" << endl;
    cout << "   1.   See the list of candidates" << endl;
    cout << "   2.   Load from file" << endl;
    cout << "   3.   Save to file" << endl;
    cout << "   4.   Add candidate" << endl;
    cout << "   5.   Remove candidate" << endl;
    cout << "   0.   Main menu" << endl;
    printHorizontalLine();
    cout << "Press a number: ";
}

void printPositionsMenu() {
    printHorizontalLine();
    cout << "Command action:" << endl;
    cout << "   1.   See the list of jobs" << endl;
    cout << "   2.   Load from file" << endl;
    cout << "   3.   Save to file" << endl;
    cout << "   4.   Add position" << endl;
    cout << "   5.   Remove position" << endl;
    cout << "   6.   See successfully closed positions" << endl;
    cout << "   0.   Main menu" << endl;
    printHorizontalLine();
    cout << "Press a number: ";
}

void printCompaniesMenu() {
    printHorizontalLine();
    cout << "Command action:" << endl;
    cout << "   1.   See the list of companies" << endl;
    cout << "   2.   Load from file" << endl;
    cout << "   3.   Save to file" << endl;
    cout << "   4.   Add company" << endl;
    cout << "   5.   Remove company" << endl;
    cout << "   0.   Main menu" << endl;
    printHorizontalLine();
    cout << "Press a number: ";
}

