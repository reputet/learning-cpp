#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>

using namespace std;

void print_horizontal_line() {
    cout << "-----------------------------------";
    cout << endl;
}

void print_menu() {
    print_horizontal_line();
    cout << "How do you want to read the array? \n";
    cout << "   1.   From the file \n";
    cout << "   2.   From the keyboard \n";
    cout << "   0.   Exit \n";
    print_horizontal_line();
    cout << "Press a number: ";
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
                if (number < 1) {
                    cout << "ERROR: the number must be greater than 0: ";
                    continue;
                }
                // Success
                break;
            }
        }
        cout << "ERROR: a number must be entered: ";
    }
    return number;
}

string get_input(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
}

bool _is_file_exists(string name) {
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
        if (_is_file_exists(name)) {
            file_found = true;
        } else {
            cout << "No such file. Try another name: " << endl;
        }
    }
    return name;
}

string get_content(string filename) {
    ifstream inFile;
    string content;
    stringstream strStream;
    inFile.open(filename);
    strStream << inFile.rdbuf();
    content = strStream.str();
    return content;
}

void enter_array(int &rows, int &columns, int* &arrayA) {
    cout << "Enter array: \n";
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            cin >> arrayA[row*columns + column];
        }
    }
}

int* extract_array_size(string input_file) {
    int rows, columns;
    int* arrayZ = new int[2];
    ifstream inFile;
    inFile.open(input_file);
    inFile >> rows >> columns;
    arrayZ[0] = rows;
    arrayZ[1] = columns;
    return arrayZ;
}

int* extract_array(string input_file, int rows, int columns) {
    int* arrayZ;
    int tmp;
    string content;
    ifstream inFile;
    inFile.open(input_file);
    inFile >> rows >> columns;
    arrayZ = new int[rows * columns];
    int i = 0;
    while (inFile >> tmp) {
        arrayZ[i] = tmp;
        i++;
    }
    inFile.close();
    return arrayZ;
}

int main() {
    // variables
    int rows, columns;
    int* arrayA;
    int* arrayB;

    // ifstream fin;
    // ofstream fout;

    // open files and check them
    /*
    fin.open("A.txt");
    fout.open("B.txt");
    if (!fin) // (fin/fail())
    if (!fout) // (fout/fail())

    */
    // ---

    char choise;
    string input_file;
    string content;
    bool exit = false;

    while (!exit) {
        print_menu();
        choise = getche();
        switch (choise) {
            case '1':
                input_file = get_filename("\nPlease, enter the filename: ");
                rows = extract_array_size(input_file)[0];
                columns = extract_array_size(input_file)[1];
                arrayA = extract_array(input_file, rows, columns);
                exit = true;
                break;
            case '2':
                cout << "\n\n";
                rows = get_int("Enter matrix size (rows): ");
                columns = get_int("Enter matrix size (columns): ");
                arrayA = new int[rows * columns];
                enter_array(rows, columns, arrayA);
                exit = true;
                break;
            case '0':
                exit = true;
                // delete[] arrayA;
                // delete[] arrayB;
                return 0;
        }
    }

    // input arrya from keyboard

    // check N and M (N > 0) (M > 0)

    // arrayA = new int[rows * columns];
    arrayB = new int[columns * rows];

    // cout << "Enter array: \n";
    // for(int row = 0; row < rows; row++)
    // {
    //     for(int column = 0; column < columns; column++)
    //     {
    //         cin >> arrayA[row*columns + column];
    //     }
    // }
    
    // ---
    
    // output the array
    cout << "First array: \n";
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            cout << arrayA[row*columns + column] << "\t";
        }
        cout << "\n";
    }

    // ---

    // tranform the array
    cout << "Transforming array ... \n";
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            arrayB[column*rows + row] = arrayA[row*columns + column];
            //arrayB[j][i] = arrayA[i][j];
        }
    }
    
    // ---

    // output the array
    cout << "Second array: \n";
    for(int row = 0; row < columns; row++)
        {
            for(int column = 0; column < rows; column++)
            {
                cout << arrayB[row*rows + column] << "\t";
            }
            cout << "\n";
        }
    
    // ---

    // close files
    /*
    fin.close();
    fout.close();
    */

    // delete arrays
    delete[] arrayA;
    delete[] arrayB;

    return 0;

/*

   int N , M;
   int* arrayA = nullptr;
   int* aarayB = nullptr;

   ifstream fin;
   ofstraem fout;

   openFIN(fin); // emter the name of file and cjeck
   openFOUT(fout); // enter the name of file and check

   inputArray(arrayA, N, M); // input from keyboard
   // inputArray(int* &array, int &N, int &M);
   inputArrayFromFile(fin, arrayA, N ,M);
   
   outputArray(arrayA, N, M) // ouput to console

   transfromArray(arrayA, arrayB, N, M);
   // transfromArray(int* arrayA, int* &arrayB, int N, int M);

   outputArray(array, M, N);

   outputArrayToFile(arrayB, M, N);

   fin.close();
   fout.close;

   if (arrayA != nu;lptr) delete[] arrayA;
   if (arrayB != nullptr) delete[] arrayB;

   retrun 0;
*/
}
