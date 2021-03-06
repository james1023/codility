# codility
The codility code is referenced by myself.

[Lesson 1 Iterations]  

- BinaryGap  
Find longest sequence of zeros in binary representation of an integer.  
For example, number 9 has binary representation 1001 and contains a binary gap of length 2.  
The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.  
The number 20 has binary representation 10100 and contains one binary gap of length 1.  
The number 15 has binary representation 1111 and has no binary gaps.
  
[Lesson 2 Arrays]  

- OddOccurrencesInArray  
Find value that occurs in odd number of elements.  
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9  
the function should return 7
  
- CyclicRotation  
Rotate an array to the right by a given number of steps.  
For example, given array A = [3, 8, 9, 7, 6] and K = 3, the function should return [9, 7, 6, 3, 8].
  
[Lesson 3 Time Complexity]  

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

[Lesson 4 Counting Elements]  

- PermCheck  
Check whether array A is a permutation.  
For example, given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.  
Given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.  
  
- MissingInteger  
Find the minimal positive integer not occurring in a given sequence.  
For example, given:
  A[0] = 1
  A[1] = 3
  A[2] = 6
  A[3] = 4
  A[4] = 1
  A[5] = 2
the function should return 5.  
  
[Lesson 6 Sorting]  
   
- Distinct  
Compute number of distinct values in an array.  
A[0] = 2    A[1] = 1    A[2] = 1    A[3] = 2    A[4] = 3   A[5] = 1  
the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.   
   

   
