#include <stdio.h>

#include <set>

/*
int solution(vector<int> &A) {
 // write your code in C++11 (g++ 4.8.2)
 set<int> s;
 
 for (auto i: A) {
 if (s.find(i) == s.end()) {
            s.insert(i);
        } else {
            s.erase(i);
        }
    }
 
 return *s.begin();
}
*/

int solution(int A[], int N);
int solution(int A[], int N)
{
    int sol = 0;
    for (int i = 0; i < N; ++i)
        sol ^= A[i];

    return sol;
}

int main(void)
{
    int A[] = {9, 3, 9, 3, 9, 7, 9, 7, 4};

    printf("%d\n", solution(A, 9));

	getchar();
}
