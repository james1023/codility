#include <stdio.h>

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution2(vector<int> &A) {
 // write your code in C++11 (g++ 4.8.2)
	sort(A.begin(), A.end());

	int s = int(A.size());

	int m1 = A[s - 1] * A[s - 2] * A[s - 3];
	if ((A[s - 1] < 0) || (A[0] > 0)) return m1;

	int m2 = A[0] * A[1] * A[s - 1];
 
 return max(m1, m2);
}


int solution(int A[], int N);
int solution(int A[], int N)
{
    // Find the largest 3 and smallest 2
    int max[3] = {0}, min[2] = {0}, n = N;
    for (int k = 0; k < 3; ++k) {
        int m = A[0], index = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] > m) {
                m = A[i];
                index = i;
            }
        }
        max[k] = m;
        A[index] = A[--n];
        A[n] = m;
    }
    for (int k = 0; k < 2; ++k) {
        int m = A[0], index = 0;
        for (int i = 1; i < N; ++i) {
            if (A[i] < m) {
                m = A[i];
                index = i;
            }
        }
        min[k] = m;
        A[index] = A[--N];
        A[N] = m;
    }
    int result = max[0] * max[1] * max[2];
    if (result < max[0] * min[0] * min[1])
        result = max[0] * min[0] * min[1];
    return result;
}

int main(void)
{
    int A[] = {-3, 1, 2, -2, 5, 6};
    int B[] = {5, 3, -5, -5};

    //printf("%d\n", solution(A, 6));
    //printf("%d\n", solution(B, 4));

	printf("%d\n", solution2(vector<int>(A, A+6)));

	std::cin.get();

    return 0;
}
