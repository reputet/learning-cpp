#pragma once
#include <iostream>
// #include "./ArrayList.h"
#include "./LinkedList.h"
using namespace std;

string getInput(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
}

// ArrayList<string> splitString(string s, string delimeter) {
//     ArrayList<string> result = ArrayList<string>();
//     int start = 0;
//     int end = end = s.find_first_of(delimeter);
//     while (end != -1) {
//         result.add(s.substr(start, end - start));
//         start = end + 1;
//         end = s.find_first_of(delimeter, start);
//     }
//     result.add(s.substr(start));
//     return result;
// }

LinkedList<string> splitStringFoo(string s, string delimeter) {
    LinkedList<string> result = LinkedList<string>();
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


bool isFileExists(string name) {
    ifstream inFile;
    inFile.open(name);
    if (inFile) {
        return true;
    }
    return false;
}

string getFilename(string message) {
    string name;
    bool file_found = false;
    while (!file_found) {
        name = getInput(message);
        if (isFileExists(name)) {
            file_found = true;
        } else {
            cout << "No such file. Try another name: " << endl;
        }
    }
    return name;
}
