#include "remove-word.h"

string get_input(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
}

string remove_occurences(string str, string word) {
    size_t pos = 0;
    int count = 0;
    do {
        pos = str.find(word, pos);
        if(pos != string::npos)
        {
            count++;
            if (count % 2 == 0)
            {
              str.erase(pos, word.length());
            }
            else
            {
                pos += word.length();
            }
        }
    } while (pos != string::npos);
    return str;
}

int main() {
    string original_str, new_str, word;
    original_str = get_input("Enter the string: ");
    word = get_input("Enter the word: ");
    new_str = remove_occurences(original_str, word);
    cout << "Original string is: " << original_str << endl;
    cout << "New string is     : " << new_str << endl;
    return 0;
}
