#include <stdio.h>

/*
int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	set<int> s;
	int maximum = 1;
	for (auto i: A) {
		if (s.find(i) == s.end()) {
				s.insert(i);
		}
		else {
			return false;
		}
		maximum = max(i, maximum);
	}
 
	return (maximum == s.size());
}
*/

int solution(int A[], int N)
{
    for (int i = 0; i < N; ++i) {
        for (int num = A[i] - 1; 0 <= num && num < N && A[num] != num + 1;
                num = A[i] - 1) {
            int tmp = A[num];
            A[num] = A[i];
            A[i] = tmp;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (A[i] != i + 1)
            return 0;
    }
    return 1;
}

int main(void)
{
    int A[] = {4, 1, 3, 2};
    int B[] = {4, 1, 3};

    printf("%d\n", solution(A, 4));
    printf("%d\n", solution(B, 3));
}
