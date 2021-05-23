#include "matrix.h"

void input_array(int *array, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // string message = "input [" + to_string(i) + "][" + to_string(j) + "] element: ";
            array[i * n + j] = get_int("input [" + to_string(i) + "][" + to_string(j) + "] element: ");
        }
    }
}

void modify_array(int *array, int n, int diff) {
    for(int i=0; i<n; i++) {
        array[i * n + i] -= diff;
    }
}

void print_array(int *array, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout.width(5);
            cout << array[i * n + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int get_int (string message) {
    string line;
    int number;
    cout << message;
    while (true) {
        getline(cin, line);
        stringstream ss(line);
        if (ss >> number) {
            if (ss.eof()) {
                // Success
                break;
            }
        }
        cout << "ERROR: a number must be entered: ";
    }
    return number;
}

int main() {
    int n = get_int("Input the size of the matrix: ");

    int arr[n][n];

    input_array(arr[0], n);
    cout << endl << "Here is the matrix before the modification" << endl;
    print_array(arr[0], n);

    int diff = get_int("Input the diff value: ");
    modify_array(arr[0], n, diff);

    cout << endl << "Here is the matrix after the modification" << endl;
    print_array(arr[0], n);
}
