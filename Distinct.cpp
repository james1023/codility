#include <stdio.h>
#include <stdlib.h>

#include <set>

/*
that, given a zero-indexed array A consisting of N integers, returns the number of distinct values in array A.

For example, given array A consisting of six elements such that:
A[0] = 2    A[1] = 1    A[2] = 1
A[3] = 2    A[4] = 3    A[5] = 1
the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.
*/

/*
int solution(vector<int> &A) {
 // write your code in C++11 (g++ 4.8.2)
 set<int> s;
 for (auto i: A) {
        s.insert(i);
    }
 
 return int(s.size());
}
*/

int compare(const void *p, const void *q);
int solution(int A[], int N);

int compare(const void *p, const void *q)
{
    int x = *(const int *)p;
    int y = *(const int *)q;
    return (x == y) ? 0 : ((x < y) ? -1 : 1);
}

int solution(int A[], int N)
{
    qsort(A, N, sizeof(int), compare);
    int result = 0;
    for (int i = 0; i < N; ++i)
        if (i == 0 || A[i] != A[i - 1])
            ++result;
    return result;
}

int main(void)
{
    int A[] = {2, 1, 1, 2, 3, 1};

    printf("%d\n", solution(A, 6));
}
