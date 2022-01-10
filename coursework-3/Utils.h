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

string get_input(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
}


bool is_file_exists(string name) {
    ifstream inFile;
    inFile.open(name);
    if (inFile) {
        return true;
    }
    return false;
}

string get_filename(string message) {
    string name;
    bool file_found = false;
    while (!file_found) {
        name = get_input(message);
        if (is_file_exists(name)) {
            file_found = true;
        } else {
            cout << "No such file. Try another name: " << endl;
        }
    }
    return name;
}
