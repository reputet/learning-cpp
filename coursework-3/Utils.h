#pragma once
#include <iostream>
#include "./ArrayList.h"
using namespace std;

string getInput(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
}

ArrayList<string> splitString(string s, string delimeter) {
    ArrayList<string> result = ArrayList<string>();
    int start = 0;
    int end = end = s.find_first_of(delimeter);
    while (end != -1) {
        result.add(s.substr(start, end - start));
        start = end + 1;
        end = s.find_first_of(delimeter, start);
    }
    result.add(s.substr(start));
    return result;
}
