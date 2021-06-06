#include <conio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void pause();
void print_horizontal_line();
void print_menu(string, string, bool);
string get_input(string);
bool is_file_exists(string);
string get_filename(string);
string get_content(string);
int get_sentences_number(string);
string *split_sentences(string, int);
int *get_relevant_sentences_numbers(string *, int, string);
void print_sentences(string *, int *, string);
void append_word(string *, string, int, string);
void remove_char(string *, char, int);
void remove_all_chars(string *, int);
void write_to_file(string, string *, int);
void append_to_sentences(string *, string, int *);
void remove_in_sentences(string *, string, int *);
void change_sentence(string *, string, int *);
