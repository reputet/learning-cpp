#pragma once
#include <fstream>
#include "./ArrayList.h"
using namespace std;

string getInput(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
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

ArrayList<string> readFileToList(string filename) {
    string line;    
    ifstream infile(filename);
    ArrayList<string> result;
    while (getline(infile, line)) {
        result.add(line);
    }
    return result;
}