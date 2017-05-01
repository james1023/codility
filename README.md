# codility
The codility code is referenced by myself.

Lesson 1 Iterations  

- BinaryGap
Find longest sequence of zeros in binary representation of an integer.  

For example, number 9 has binary representation 1001 and contains a binary gap of length 2.  
The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.  
The number 20 has binary representation 10100 and contains one binary gap of length 1.  
The number 15 has binary representation 1111 and has no binary gaps.


Lesson 2 Arrays  

- OddOccurrencesInArray
Find value that occurs in odd number of elements.  

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9  
the function should return 7

- CyclicRotation
Rotate an array to the right by a given number of steps.  

For example, given array A = [3, 8, 9, 7, 6] and K = 3, the function should return [9, 7, 6, 3, 8].

- PermMissingElem  
Find the missing element in a given permutation.   

  A[0] = 2  A[1] = 3  A[2] = 1  A[3] = 5 
the function should return 4, as it is the missing element.   

- TapeEquilibrium
Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.  
  A[0] = 3  A[1] = 1  A[2] = 2  A[3] = 4  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7 
P = 2, difference = |4 − 9| = 5 
P = 3, difference = |6 − 7| = 1 
P = 4, difference = |10 − 3| = 7 
