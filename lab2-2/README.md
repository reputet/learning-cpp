# Main diagonal subtraction

The program asks you to specify a matrix size of n and all the elements. Then
you define all the elements of the matrix and a `diff` value. This value will
be subtracted from all the elements in the main diagonal of the matrix.

# Example

```
$ ./matrix
Input the size of the matrix: 3
input [0][0] element: 1
input [0][1] element: 2
input [0][2] element: 3
input [1][0] element: 4
input [1][1] element: 5
input [1][2] element: 6
input [2][0] element: 7
input [2][1] element: 8
input [2][2] element: 9

Here is the matrix before the modification
    1     2     3
    4     5     6
    7     8     9

Input the diff value: 100

Here is the matrix after the modification
  -99     2     3
    4   -95     6
    7     8   -91
```
