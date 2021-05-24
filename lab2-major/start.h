#include <iostream>
#include <fstream> 
#include <sstream>

using namespace std;

string get_input(string);
string get_content(string);
int get_int (string);
int get_number_of_sentences (string);
string *split(string, int);
int *get_number_of_sentences_with_word(string *, int, string);
void print_sentences(string *, int *, string);
void append_word(string *, string, int, string);
void remove_char(string *, string, int);
void write_to_file(string, string *, int);
void change_sentence(string *, string, int *);