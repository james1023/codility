#include <stdio.h>
#include <stdlib.h>

/*
vector<int> solution(int N, vector<int> &A) {
 // write your code in C++11 (g++ 4.8.2)
 vector<int> res(N, 0);
 
 int base = 0;
 int maximum = 0;
 for (int i = 0; i < int(A.size()); i++) {
 if (A[i] != N + 1) {
            res[A[i] - 1] = max(base, res[A[i] - 1]) + 1;
            maximum = max(maximum, res[A[i] - 1]);
        } else {
            base = maximum;
        }
    }
 
 for (int i = 0; i < N; i++) {
 if (res[i] < base) {
            res[i] = base;
        }
    }
 return res;
}
*/

struct Results {
    int *C;
    int L;
};

struct Results solution(int N, int A[], int M) {
    struct Results result = {calloc(N, sizeof(int)), N};
    int last = 0, max = 0;
    for (int i = 0; i < M; ++i) {
        if (A[i] < N + 1) {
            if (result.C[A[i] - 1] < last)
                result.C[A[i] - 1] = last;
            if (++result.C[A[i] - 1] > max)
                max = result.C[A[i] - 1];
        } else
            last = max;
    }
    for (int i = 0; i < N; ++i) {
        if (result.C[i] < last)
            result.C[i] = last;
    }
    return result;
}

int main(void)
{
    int A[] = {3, 4, 4, 6, 1, 4, 4, 6};
    struct Results result = solution(5, A, 8);
    for (int i = 0; i < 5; ++i)
        printf("%d ", result.C[i]);
    puts("");
    return 0;
}
