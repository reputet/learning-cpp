#include "sort.h"

string get_input(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
}

int get_int(string message) {
    string line;
    int number;
    cout << message;
    while (true) {
        getline(cin, line);
        stringstream ss(line);
        if (ss >> number) {
            if (number < 1) {
                cout << "ERROR: a positive number must be entered: ";
                continue;
            } else if (ss.eof()) {
                // Success
                break;
            }
        }
        cout << "ERROR: a number must be entered: ";
    }
    return number;
}

void input_array(string *arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i * columns + j] = get_input(
                "input [" + to_string(i) + "][" + to_string(j) + "] element: ");
        }
    }
    cout << endl;
}

void swap_elements(string *element1, string *element2) {
    string temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

void print_array(string *arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout.width(7);
            cout << arr[i * columns + j] << " ";
        }
        cout << endl;
    }
}

void sort_array(string *arr, int rows, int columns) {
    // Selection sorting
    int length = rows * columns;
    int shift = 0;
    string* min_word;

    for (int shift = 0; shift < length; shift++) {
        int min_element = arr[shift].length();
        min_word = &arr[shift];
        for (int element=shift + 1; element < length; element++) {
            string& word = arr[element];
            if (word.length() < min_element) {
                min_word = &word;
                min_element = word.length();
            }
        }
        swap_elements(min_word, &arr[shift]);
    }
}

int main() {
    int rows;
    int columns;

    rows = get_int("Input the number of rows: ");
    columns = get_int("Input the number of columns: ");
    string arr[rows][columns];

    input_array(arr[0], rows, columns);

    cout << "The array before the sorting: \n\n";
    print_array(arr[0], rows, columns);

    sort_array(arr[0], rows, columns);

    cout << "\nThe array after the sorting: \n\n";
    print_array(arr[0], rows, columns);
}
