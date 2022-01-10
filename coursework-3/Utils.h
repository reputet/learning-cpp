#pragma once
#include <iostream>
using namespace std;

string getInput(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
}