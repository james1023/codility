#include <stdio.h>

/*
int solution(vector<int> &A) {
 // write your code in C++11 (g++ 4.8.2)
 vector<int> pre_sum(A.size(), 0);
 
 int s = 0;
 for (size_t i = 0; i < A.size(); i++) {
        s += A[i];
        pre_sum[i] = s;
    }
 
 int res = 0;
 
 for (int i = int(A.size() - 1); i >= 0; i--) {
 if (A[i] == 0) {
            res += (pre_sum[A.size() - 1] - pre_sum[i]);
 if (res > 1000000000) return -1;
        }
    }
 
 return res;
}
*/

int solution(int A[], int N) 
{
    int result = 0, zeros = 0;
    for (int i = 0; i < N; ++i)
        if (A[i] == 1) {
            if (1000000000 - zeros >= result)
                result += zeros;
            else
                return -1;
        } 
		else
            ++zeros;

    return result;
}

int main(void)
{
    int A[] = {0, 1, 0, 1, 1};
    printf("%d\n", solution(A, 5));
    return 0;
}
