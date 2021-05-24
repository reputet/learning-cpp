# Example

```
$ ./start
Enter the existing filename: input.txt
The content of the file input.txt is:

Bar1. Bar2. Foo1.
Bar3. Foo2 bla, bla, hey, how are you doing. aslkdfjdsf. sldkjf.
sadlkfj. another Foo3. aosdkf

Good morning, please and thank you
Not very hard to say,
But little deeds
Like little words
Can make or mar your day.
Say these few words often,
With a pleasant smile.
This can lighten many a load and
Shorten many a mile.  And Foo4. qwe.
qweWW.

Enter a word for search: Foo

The word Foo is found in the following sentences:

3:  Foo1.
5:  Foo2 bla, bla, hey, how are you doing.
9:  another Foo3.
13:   And Foo4.

Please, choose the sentences you want to change: 5
Enter a word you want to append: Bar
Enter a character you want to remove: ,

Here are the lines after changes:

3:  Foo1.
5:  FooBar2 bla bla hey how are you doing.
9:  another Foo3.
13:   And Foo4.
```
