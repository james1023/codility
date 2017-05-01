#include <stdio.h>

#include <vector>

int solution(int X, int A[], int N)
{
	int count = 0;
#if 1
	std::vector<int> visited(X+1);
#else
	int visited[X + 1];
	for (int i = 0; i <= X; ++i)
		visited[i] = 0;
#endif
    
    for (int i = 0; i < N; ++i)
        if (A[i] <= X && visited[A[i]] == 0) {
            ++count;
            visited[A[i]] = 1;
            if (count == X)
                return i;
        }
    return -1;
}

int main(void)
{
    int A[] = {1, 3, 1, 4, 2, 3, 5, 4};
    int B[] = {2, 3, 1, 4};
    int C[] = {1};
    printf("%d\n", solution(5, A, 8));
    printf("%d\n", solution(2, C, 1));
}
