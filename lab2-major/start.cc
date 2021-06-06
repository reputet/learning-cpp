#include "./start.h"

void pause() {
    cout << endl;
    system("pause");
    cout << endl;
}

void print_horizontal_line() {
    cout << "-----------------------------------";
    cout << endl;
}

void print_menu(string input_file, string output_file, bool print_nothing) {
    if (print_nothing) {
        return;
    }
    if (input_file.empty()) {
        input_file = "<not set>";
    }
    if (output_file.empty()) {
        output_file = "<not set>";
    }
    print_horizontal_line();
    cout << "Input file: " << input_file << endl;
    cout << "Output file: " << output_file  << endl << endl;
    cout << "Command action:" << endl;
    cout << "   1.   Set input file name" << endl;
    cout << "   2.   Add a word after another word" << endl;
    cout << "   3.   Remove a punctuation char (one or all)" << endl;
    cout << "   4.   Set output file name" << endl;
    cout << "   5.   Save and exit" << endl;
    cout << "   0.   Exit without saving" << endl;
    print_horizontal_line();
    cout << "Press a number: ";
}

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

string get_content(string filename) {
    ifstream inFile;
    string message;
    string content;
    stringstream strStream;
    inFile.open(filename);
    strStream << inFile.rdbuf();
    content = strStream.str();
    return content;
}

int get_sentences_number(string content) {
    string sentences_delimeter = ".";
    int num = 0;
    for (int i=0; i < content.length(); i++) {
        for (int j=0; j < sentences_delimeter.length(); j++) {
            if (content[i] == sentences_delimeter[j]) {
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

string *split_sentences(string content, int all_sentences_number) {
    string sentence;
    string *sentences_array;
    string delimeter;
    int start, end, counter;

    delimeter = ".";
    counter = 0;
    start = 0;
    end = content.find(delimeter);
    sentences_array = new string[all_sentences_number];

    while (end != -1) {
        sentence = content.substr(start, end + 1 - start);
        sentences_array[counter] = sentence;
        start = end + 1;
        end = content.find(delimeter, start);
        counter++;
    }
    return sentences_array;
}

int *get_relevant_sentences_numbers(string *all_sentences,
                                    int number_of_sentences,
                                    string word) {
    int array_length;
    int *numbers = new int[number_of_sentences + 1];
    int counter = 1;
    for (int i=0; i < number_of_sentences; i++) {
        if (all_sentences[i].find(word) != string::npos) {
            numbers[counter] = i;
            counter++;
            continue;
        }
    }
    array_length = counter - 1;
    numbers[0] = array_length;
    return numbers;
}

void print_sentences(string *all_sentences, int *sentences_with_word,
                     string word) {
    int i = 0;
    cout << endl;
    print_horizontal_line();
    while (i < sentences_with_word[0]) {
        cout << all_sentences[sentences_with_word[i + 1]];
        i++;
    }
    cout << endl;
    print_horizontal_line();
}

void append_word(string *all_sentences, string word, int number_of_sentences,
                 string word_to_append) {
    string &content = all_sentences[number_of_sentences - 1];
    int start, end, counter;
    start = 0;
    end = content.find(word);
    while (end != string::npos) {
        start = end + 1;
        content.insert(end + word.length(), word_to_append);
        end = content.find(word, start);
    }
}

void remove_char(string *all_sentences, char char_to_remove,
                 int number_of_sentences) {
    string &content = all_sentences[number_of_sentences - 1];
    int position;
    while ((position = content.find(char_to_remove)) != string::npos) {
        content.erase(position, 1);
    }
}

void remove_all_chars(string *all_sentences, int number_of_sentences) {
    string &content = all_sentences[number_of_sentences - 1];
    string punctuation_chars = ",:;-";
    char char_to_remove;
    int position;
    for (int i=0; i < punctuation_chars.length(); i++) {
        char_to_remove = punctuation_chars[i];
        while ((position = content.find(char_to_remove)) != string::npos) {
            content.erase(position, 1);
        }
    }
}

void write_to_file(string filename, string *all_sentences,
                   int number_of_sentences) {
    ofstream to_file(filename);
    string content;
    for (int i=0; i < number_of_sentences; i++) {
        content.append(all_sentences[i]);
    }
    content.append("\n");
    to_file << content;
}

void append_to_sentences(string *all_sentences, string word,
                         int *sentences_with_word) {
    int sentence_to_change;
    int sentences_number;
    string word_to_append;
    string char_to_remove;
    sentences_number = sentences_with_word[0];
        word_to_append = get_input("Enter a word you want to append: ");
        for (int i=0; i < sentences_number; i++) {
            sentence_to_change = sentences_with_word[i + 1] + 1;
            append_word(
                all_sentences,
                word,
                sentence_to_change,
                word_to_append);
        }
        cout << endl;
        cout << "The modified sentences are: ";
        print_sentences(all_sentences, sentences_with_word, word);
        pause();
}

void remove_in_sentences(string *all_sentences, string word,
                         int *sentences_with_word) {
    int sentence_to_change;
    int sentences_number;
    string word_to_append;
    string char_to_remove;
    char choise;
    bool exit;
    sentences_number = sentences_with_word[0];
    cout << "What character do you want to remove?" << endl;
    cout << "   (,)   to remove the commas" << endl;
    cout << "   (:)   to remove the collons" << endl;
    cout << "   (;)   to remove the semicolons" << endl;
    cout << "   (-)   to remove the hyphens" << endl;
    cout << "   (a)   to remove all the punctuation characters" << endl;
    print_horizontal_line();
    cout << "Choose a character: ";
    while (!exit) {
        choise = getche();
        switch (choise) {
            case ',':
                cout << endl;
                for (int i=0; i < sentences_number; i++) {
                    sentence_to_change = sentences_with_word[i + 1] + 1;
                    remove_char(all_sentences, choise, sentence_to_change);
                }
                exit = true;
                break;
            case ':':
                cout << endl;
                for (int i=0; i < sentences_number; i++) {
                    sentence_to_change = sentences_with_word[i + 1] + 1;
                    remove_char(all_sentences, choise, sentence_to_change);
                }
                exit = true;
                break;
            case ';':
                cout << endl;
                for (int i=0; i < sentences_number; i++) {
                    sentence_to_change = sentences_with_word[i + 1] + 1;
                    remove_char(all_sentences, choise, sentence_to_change);
                }
                exit = true;
                break;
            case '-':
                cout << endl;
                for (int i=0; i < sentences_number; i++) {
                    sentence_to_change = sentences_with_word[i + 1] + 1;
                    remove_char(all_sentences, choise, sentence_to_change);
                }
                exit = true;
                break;
            case 'a':
                cout << endl;
                for (int i=0; i < sentences_number; i++) {
                    sentence_to_change = sentences_with_word[i + 1] + 1;
                    remove_all_chars(all_sentences, sentence_to_change);
                }
                exit = true;
                break;
            default:
                cout << endl;
                cout << "Wrong input. Try again." << endl;
                cout << "Choose a character: ";
                break;
        }
    }
    cout << endl;
    cout << "The modified sentences are: ";
    print_sentences(all_sentences, sentences_with_word, word);
    pause();
}

int main() {
    string input_file;
    string output_file;
    string content;
    string word;
    string *sentences_list;
    int number_of_sentences;
    int *sentences_number_with_word;
    char choise;
    bool exit;
    bool suppress_menu;

    exit = false;
    suppress_menu = false;
    while (!exit) {
        print_menu(input_file, output_file, suppress_menu);
        suppress_menu = false;
        choise = getche();
        switch (choise) {
            case '1':
                cout << endl;
                input_file = get_filename("Please, enter the filename: ");
                content = get_content(input_file);
                cout << endl << "The content of the file is:" << endl;
                print_horizontal_line();
                cout << content;
                print_horizontal_line();
                number_of_sentences = get_sentences_number(content);
                sentences_list = split_sentences(content, number_of_sentences);
                pause();
                break;
            case '2':
                cout << endl;
                if (input_file.empty()) {
                    cout << "Specify the input file name (1) first" << endl;
                    cout << "Press a number: ";
                    suppress_menu = true;
                    break;
                }
                do {
                    word = get_input("Enter a word to find the sentences: ");
                    sentences_number_with_word = get_relevant_sentences_numbers(
                        sentences_list,
                        number_of_sentences,
                        word);
                    if (!sentences_number_with_word[0]) {
                        cout << "The word '" << word
                        << "' was not found. Try again." << endl;
                    }
                } while (!sentences_number_with_word[0]);
                cout << endl;
                cout << "The word '" << word
                     << "' is found in the following sentences:";
                print_sentences(sentences_list, sentences_number_with_word,
                                word);
                cout << endl;
                append_to_sentences(sentences_list, word,
                                    sentences_number_with_word);
                break;
            case '3':
                cout << endl;
                if (input_file.empty()) {
                    cout << "Specify the input file name (1) first" << endl;
                    cout << "Press a number: ";
                    suppress_menu = true;
                    break;
                }
                do {
                    word = get_input("Enter a word to find the sentences: ");
                    sentences_number_with_word = get_relevant_sentences_numbers(
                        sentences_list,
                        number_of_sentences,
                        word);
                    if (!sentences_number_with_word[0]) {
                        cout << "The word" << " '" << word
                             << "' " << "was not found. Try again." << endl;
                    }
                } while (!sentences_number_with_word[0]);
                cout << endl;
                cout << "The word '" << word
                     << "' is found in the following sentences:";
                print_sentences(sentences_list, sentences_number_with_word,
                                word);
                pause();
                remove_in_sentences(sentences_list, word,
                                    sentences_number_with_word);
                break;
            case '4':
                cout << endl;
                output_file = get_input("Enter the output file name: ");
                cout << endl;
                break;
            case '5':
                cout << endl;
                if (output_file.empty()) {
                    cout << "Specify the output file name (4) first" << endl;
                    cout << "Press a number: ";
                    suppress_menu = true;
                    break;
                }
                write_to_file(output_file, sentences_list, number_of_sentences);
                cout << "Saved" << endl;
                cout << "Buy!" << endl;
                return 0;
            case '0':
                cout << endl << "Buy" << endl;
                return 0;
            default:
                cout << endl;
                cout << "Wrong input. Try again." << endl;
                cout << "Press a number: ";
                suppress_menu = true;
                break;
        }
    }
    return 0;
}
