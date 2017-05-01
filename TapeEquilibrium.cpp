#include <stdio.h>

#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <gtest/gtest.h>

using namespace std;

int solution2(vector<int> &A) 
{
 // write your code in C++11 (g++ 4.8.2)
	vector<int> pre_sum;
	int s = 0;
	for (auto i : A) {
		s += i;
		pre_sum.push_back(s);
	}

	int min_abs_diff = numeric_limits<int>::max();
	for (size_t i = 1; i < pre_sum.size(); i++) {
		int abs_diff = abs(pre_sum[i - 1] * 2 - pre_sum[pre_sum.size() - 1]);
		min_abs_diff = min(min_abs_diff, abs_diff);
	}

	return min_abs_diff;
}


int solution(int A[], int N)
{
    int sumRight = 0, sumLeft = 0, minDiff = 1 << 30;

    for (int i = 0; i < N; ++i)
        sumRight += A[i];
    for (int i = 0; i < N - 1; ++i) {
        sumLeft += A[i];
        sumRight -= A[i];
        int diff = sumLeft - sumRight;
        diff = diff >= 0 ? diff : -diff;
        minDiff = minDiff < diff ? minDiff : diff;
    }
    return minDiff;
}

TEST(TapeEquilibrium, test0)
{
	std::vector<int> in{ 3, 1, 2, 4, 3 };
	EXPECT_EQ(1, solution2(in));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	//int A[] = { 3, 1, 2, 4, 3 };
	//printf("%d\n", solution(A, 5));

	std::cin.get();
}
