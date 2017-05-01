#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

int compare(const void *p, const void *q);
int compare(const void *p, const void *q)
{
    int x = *(const int *)p;
    int y = *(const int *)q;
    return (x == y) ? 0 : ((x < y) ? -1 : 1);
}

int solution(int A[], int N);
int solution(int A[], int N)
{
    qsort(A, N, sizeof(int), compare);
    for (int i = 1; i < N - 1; ++i)
        if (A[i + 1] - A[i] < A[i - 1])
            return 1;
    return 0;
}

bool is_triangle(int64_t a, int64_t b, int64_t c)
{
	return (a + b > c) &&
		(b + c > a) &&
		(c + a > b);
}

int solution2(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	if (A.size() < 3) return 0;

	sort(A.begin(), A.end());

	int res = 0;
	for (int i = 0; i < int(A.size() - 2); i++) {
		if (is_triangle(A[i], A[i + 1], A[i + 2])) return 1;
	}

	return 0;
}

TEST(Triangle, test0)
{
	std::vector<int> in{ 10, 2, 5, 1, 8, 20 };
	EXPECT_EQ(1, solution2(in));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

    /*int A[] = {10, 2, 5, 1, 8, 20};
    int B[] = {10, 50, 5, 1};

    printf("%d\n", solution(A, 6));
    printf("%d\n", solution(B, 4));*/

	std::cin.get();

    return 0;
}
