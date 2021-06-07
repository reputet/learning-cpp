# Task
The program allows the user to:

1. Specify a file by name;
2. Find all the sentences by with an specified occurence;
3. Add a word2 after the occurence in the found sentences;
4. Remove punctuation characters (one or many) in the found sentences;
5. Save the modified content to another file.

# Example of the program execution

```
$ ./start.exe
-----------------------------------
Input file: <not set>
Output file: <not set>

Command action:
   1.   Set input file name
   2.   Add a word after another word
   3.   Remove a punctuation char (one or all)
   4.   Set output file name
   5.   Save and exit
   0.   Exit without saving
-----------------------------------
Press a number: 1
Please, enter the filename: input.txt

The content of the file is:
-----------------------------------
Sentence 1 odd1, odd2, odd3: all.
Sentence 2 even1, even2, even3; all.
Sentence 3 odd4, odd5, odd6: all.
Sentence 4 even4, even5, even6; all.
Sentence 5 odd7, odd8, odd9: all.
Sentence 4 even7, even8, even9; all.
-----------------------------------

Press any key to continue . . .

-----------------------------------
Input file: input.txt
Output file: <not set>

Command action:
   1.   Set input file name
   2.   Add a word after another word
   3.   Remove a punctuation char (one or all)
   4.   Set output file name
   5.   Save and exit
   0.   Exit without saving
-----------------------------------
Press a number: 2
Enter a word to find the sentences: odd

The word 'odd' is found in the following sentences:
-----------------------------------
Sentence 1 odd1, odd2, odd3: all.
Sentence 3 odd4, odd5, odd6: all.
Sentence 5 odd7, odd8, odd9: all.
-----------------------------------

Enter a word you want to append:  FOOBAR

The modified sentences are:
-----------------------------------
Sentence 1 odd FOOBAR1, odd FOOBAR2, odd FOOBAR3: all.
Sentence 3 odd FOOBAR4, odd FOOBAR5, odd FOOBAR6: all.
Sentence 5 odd FOOBAR7, odd FOOBAR8, odd FOOBAR9: all.
-----------------------------------

Press any key to continue . . .

-----------------------------------
Input file: input.txt
Output file: <not set>

Command action:
   1.   Set input file name
   2.   Add a word after another word
   3.   Remove a punctuation char (one or all)
   4.   Set output file name
   5.   Save and exit
   0.   Exit without saving
-----------------------------------
Press a number: 3
Enter a word to find the sentences: even

The word 'even' is found in the following sentences:
-----------------------------------

Sentence 2 even1, even2, even3; all.
Sentence 4 even4, even5, even6; all.
Sentence 4 even7, even8, even9; all.
-----------------------------------

Press any key to continue . . .

What character do you want to remove?
   (,)   to remove the commas
   (:)   to remove the collons
   (;)   to remove the semicolons
   (-)   to remove the hyphens
   (a)   to remove all the punctuation characters
-----------------------------------
Choose a character: ;

The modified sentences are:
-----------------------------------

Sentence 2 even1, even2, even3 all.
Sentence 4 even4, even5, even6 all.
Sentence 4 even7, even8, even9 all.
-----------------------------------

Press any key to continue . . .

-----------------------------------
Input file: input.txt
Output file: <not set>

Command action:
   1.   Set input file name
   2.   Add a word after another word
   3.   Remove a punctuation char (one or all)
   4.   Set output file name
   5.   Save and exit
   0.   Exit without saving
-----------------------------------
Press a number: 3
Enter a word to find the sentences: odd

The word 'odd' is found in the following sentences:
-----------------------------------
Sentence 1 odd FOOBAR1, odd FOOBAR2, odd FOOBAR3: all.
Sentence 3 odd FOOBAR4, odd FOOBAR5, odd FOOBAR6: all.
Sentence 5 odd FOOBAR7, odd FOOBAR8, odd FOOBAR9: all.
-----------------------------------

Press any key to continue . . .

What character do you want to remove?
   (,)   to remove the commas
   (:)   to remove the collons
   (;)   to remove the semicolons
   (-)   to remove the hyphens
   (a)   to remove all the punctuation characters
-----------------------------------
Choose a character: a

The modified sentences are:
-----------------------------------
Sentence 1 odd FOOBAR1 odd FOOBAR2 odd FOOBAR3 all.
Sentence 3 odd FOOBAR4 odd FOOBAR5 odd FOOBAR6 all.
Sentence 5 odd FOOBAR7 odd FOOBAR8 odd FOOBAR9 all.
-----------------------------------

Press any key to continue . . .

-----------------------------------
Input file: input.txt
Output file: <not set>

Command action:
   1.   Set input file name
   2.   Add a word after another word
   3.   Remove a punctuation char (one or all)
   4.   Set output file name
   5.   Save and exit
   0.   Exit without saving
-----------------------------------
Press a number: 4
Enter the output file name: output.txt

-----------------------------------
Input file: input.txt
Output file: output.txt

Command action:
   1.   Set input file name
   2.   Add a word after another word
   3.   Remove a punctuation char (one or all)
   4.   Set output file name
   5.   Save and exit
   0.   Exit without saving
-----------------------------------
Press a number: 5
Saved
Buy!
```