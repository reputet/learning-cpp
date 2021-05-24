#include "start.h"

void print_horizontal_line() {
    cout << "-----------------------------------";
    cout << endl;
}
string get_input(string text) {
    string input;
    cout << text;
    getline(cin, input);
    return input;
}

string get_content(string message) {
    ifstream inFile;
    string content;
    string filename;
    stringstream strStream;
    cout << message;
    while (true) {
        getline(cin, filename);
        inFile.open(filename);
        if (inFile) {
            break;
        }
		cout << "No such file. Try another name: ";
    }
        strStream << inFile.rdbuf();
        content = strStream.str();
    return content;
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

int get_number_of_sentences (string content) {
    string delimeter = ".";
    int num = 0;
    for (int i=0; i < content.length(); i++) {
        for (int j=0; j < delimeter.length(); j++) {
            if (content[i] == delimeter[j]) {
                num += 1;
                break;
            }
        }
    }
    if (num == 0) {
        cout << "There are no sentences in the file!";
        exit(1);
    }
    return num;
}

string *split(string content, int number_of_sentences) {
    string sentence;
    string *sentences;
    string delimeter;
    int start, end, counter;

    delimeter = ".";
    counter = 0;
    start = 0;
    end = content.find(delimeter);
    sentences = new string[number_of_sentences];

    while (end != -1) {
        sentence = content.substr(start, end + 1 - start);
        sentences[counter] = sentence;
        start = end + 1;
        end = content.find(delimeter, start);
        counter++;
    }
    return sentences;
}

int *get_number_of_sentences_with_word(string *sentences_all, int n, string word) {
    int *numbers = new int[n+1];
    int counter = 1;
    for (int i=0; i < n; i++) {
        if (sentences_all[i].find(word) != string::npos) {
            numbers[counter] = i;
            counter++;
            continue;
        }
    }
    numbers[0] = counter - 1;
    return numbers;
}

void print_sentences(string *sentences_all, int *sentences_with_word, string word) {
    int i = 0;
    cout << endl;
    print_horizontal_line();
    while (i < sentences_with_word[0]) {
        cout << sentences_with_word[i + 1] + 1 << ": " << sentences_all[sentences_with_word[i + 1]] << endl;
        i++;
    }
    print_horizontal_line();
    cout << endl;
}

void append_word(string *sentences_all, string word, int sentence_number, string word_to_append) {
    string &content = sentences_all[sentence_number - 1];
    int start, end, counter;
    start = 0;
    end = content.find(word);

    while (end != string::npos) {
        start = end + 1;
        content.insert(end + word.length(), word_to_append);
        end = content.find(word, start);
    }
}

void remove_char(string *sentences_all, string char_to_remove, int sentence_number) {
    string &content = sentences_all[sentence_number - 1];
    int position;
    while ((position = content.find(char_to_remove)) != string::npos) {
        content.erase(position, char_to_remove.length());
    }
}

void write_to_file(string filename, string *sentences_all, int num) {
    ofstream to_file(filename);
    string content;
    content = "";
    for (int i=0; i < num; i++) {
        content.append(sentences_all[i]);
    }
    to_file << content;
}

void change_sentence(string *sentences_all, string word, int *sentences_with_word) {
    int sentence_to_change;
    string word_to_append;
    string char_to_remove;
    string answer;
    while (true) {
        bool z = false;
        while (z == false) {
            sentence_to_change = get_int("Please, choose the sentence you want to change: ");
            for (int i=0; i < sentences_with_word[0]; i++) {
                if (sentence_to_change == sentences_with_word[i + 1] + 1) {
                    z = true;
                    break;
                }
            }
            if (z == false) {
                cout << "Wrong sentence. Try another!" << endl;
            }
        }
        word_to_append = get_input("Enter a word you want to append: ");
        char_to_remove = get_input("Enter a character you want to remove: ");
        append_word(sentences_all, word, sentence_to_change, word_to_append);
        remove_char(sentences_all, char_to_remove, sentence_to_change);
        print_sentences(sentences_all, sentences_with_word, word);
        answer = get_input("Would you like to change something else? [y/n] ");
        while (answer != "n" and answer != "N" and answer != "y" and answer != "Y") {
            answer = get_input("Wrong input. Please, type y or n: ");
        }
        if (answer == "y" or answer == "Y") {
            continue;
        } else {
            break;
        }
    }
}

int main(){
    string content;
    string file_out;
    string word;
    string *sentences_all;
    int number_of_sentences;
    int *number_of_sentences_with_word;

    content = get_content("Enter the existing filename: ");
    cout << "The content of the file is:" << endl << endl;
    print_horizontal_line();
    cout << content << endl;
    print_horizontal_line();
    cout << endl;
    word = get_input("Enter a word for search: ");
    number_of_sentences = get_number_of_sentences(content);
    sentences_all = split(content, number_of_sentences);
    number_of_sentences_with_word = get_number_of_sentences_with_word(sentences_all, number_of_sentences, word);
    cout << "The word " << word << " is found in the following sentences:" << endl;
    print_sentences(sentences_all, number_of_sentences_with_word, word);
    change_sentence(sentences_all, word, number_of_sentences_with_word);
    file_out = get_input("Enter the output file name: ");
    write_to_file(file_out, sentences_all, number_of_sentences);
    return 0;
}