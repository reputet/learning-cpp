#include <conio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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
