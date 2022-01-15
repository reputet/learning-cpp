#include "./ArrayList.h"
#include "./Utils.h"
using namespace std;

void applyChanges(ArrayList<string> *content, char searchedSymbol) {
    for (auto &a : *content) {        
        ArrayList<string> parts;
        int start = 0;
        int end = a.find_first_of(searchedSymbol);
        while (end != -1) {
            parts.add(a.substr(start, end - start + 1));
            start = end + 2;
            end = a.find_first_of(searchedSymbol, start);
        }
        parts.add(a.substr(start));
        string temp;
        for (auto &part : parts) {
            temp.append(part);            
        }
        a = temp;
    }
}

int main() {
    string fileName = getFilename("Please enter input file name: ");
    char searchedSymbol = getInput("Please enter the symbol to find: ")[0];
    ArrayList<string> content = readFileToList(fileName);
    applyChanges(&content, searchedSymbol);
    cout << "Changed content:" << endl;
    for (auto &a : content) {
        cout << a << endl;
    }
}