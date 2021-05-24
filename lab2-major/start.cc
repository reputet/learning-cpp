#include <iostream>
#include <fstream> 
#include <sstream>
using namespace std;

string get_content(string filename) {
    ifstream inFile;
    string foo;
    inFile.open(filename);
   	if (!inFile) {
		cout << "No such file";
	}
    else {
        stringstream strStream;
        strStream << inFile.rdbuf(); //read the file
        string str = strStream.str(); //str holds the content of the file
        foo = str;
    
        //cout << str << endl; //you can do anything with the string!!!
    }
    return foo;
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

int get_number_of_sentences (string s) {
    string delimeter = ".";
    int num = 0;
    for (int i=0; i < s.length(); i++) {
        for (int j=0; j < delimeter.length(); j++) {
            if (s[i] == delimeter[j]) {
                num += 1;
                break;
            }
        }
    }
    return num;
}

string *split(string s, int number_of_sentences) {
    string sentence;
    string delimeter = ".";
    int counter = 0;
    int start = 0;
    int end = s.find(delimeter);
    string *sentences = new string[number_of_sentences];

    while (end != -1) {
        sentence = s.substr(start, end + 1 - start);
        sentences[counter] = sentence;
        start = end + 1;
        end = s.find(delimeter, start);
        counter++;
    }
    return sentences;
}

string get_input(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
}

int *get_number_of_sentences_with_word(string *s, int n, string word) {
    int *numbers = new int[n+1];
    int counter = 1;
    for (int i=0; i < n; i++) {
        if (s[i].find(word) != string::npos) {
            //cout << s[i];
            numbers[counter] = i;
            counter++;
            continue;
        }
    }
    numbers[0] = counter - 1;
    return numbers;
}

void print_sentences(string *s, int *n, string word) {
    int i = 0;
    while (i < n[0]) {
        cout << n[i + 1] + 1 << ": " << s[n[i + 1]] << endl;
        i++;
    }
    cout << endl;
}

void append_word(string *s, string word, int sentence_number, string word_to_append) {
    int position = s[sentence_number - 1].find(word);
    s[sentence_number - 1].insert(position + word.length(), word_to_append);
}

void remove_char(string *s, string char_to_remove, int sentence_number) {
    int position;
    while ((position = s[sentence_number - 1].find(char_to_remove)) != string::npos) {
        s[sentence_number - 1].erase(position, 1);
    }
}

int main(){
    string content;
    string filename = get_input("Enter the existing filename: ");
    //content = get_content("input.txt");
    content = get_content(filename);
    cout << "The content of the file " << filename << " is:" << endl << endl << content << endl;
    string word = get_input("Enter a word for search: ");
    //string word = "Foo";
    int number_of_sentences = get_number_of_sentences(content);
    string *sentences_all;
    sentences_all = split(content, number_of_sentences);
    int *number_of_sentences_with_word = get_number_of_sentences_with_word(sentences_all, number_of_sentences, word);
    cout << endl << "The word " << word << " is found in the following sentences:" << endl << endl;
    print_sentences(sentences_all, number_of_sentences_with_word, word);
    int change_sentence = get_int("Please, choose the sentences you want to change: ");
    string word_to_append = get_input("Enter a word you want to append: ");
    string char_to_remove = get_input("Enter a character you want to remove: ");
    //int change_sentence = 5;
    
    //string *foo;
    //string bar[2] = {"123456789", "www"};
    //foo = bar;
    //cout << foo[0];
    //cout << endl << "Before changes:" << endl;
    //print_sentences(sentences_all, number_of_sentences_with_word, word);
    append_word(sentences_all, word, change_sentence, word_to_append);
    remove_char(sentences_all, char_to_remove, change_sentence);
    cout << endl << "Here are the lines after changes:" << endl << endl;
    // TODO: print the whole content and save it to an output file
    print_sentences(sentences_all, number_of_sentences_with_word, word);
    //cout << foo[0];
    return 0;
}