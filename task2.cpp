
#include <limits.h>

#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <gtest/gtest.h>

using namespace std;

/*
	int min_abs_diff = numeric_limits<int>::max();
*/

/*
	sort(A.begin(), A.end());
*/

/*
	std::set<int>save_item;
	for (int i = 0; i < N; i++) {
		save_item.insert(A[i]);
	}

	for (std::set<int>::iterator iter = save_item.begin(); iter != save_item.end(); iter++) {
		// *iter
	}
*/

int solution(vector<int>& A, int K) 
{
	int n = A.size();
	int best = 1;
	int count = 1;
	for (int i = 0; i < n - K - 1; i++) {
		if (A[i] == A[i + 1])
			count = count + 1;
		else
			count = 1;
		best = max(best, count);
	}
	int result = best + (K>=n ? 0:K);

	return result;
}

TEST(task2, test0)
{
	std::vector<int> in{ 1,1,3,3,3,4,5,5,5,5 };
	EXPECT_EQ(6, solution(in, 3));
}

TEST(task2, test1)
{
	std::vector<int> in{ 1,1,1,1,3,4,5,5,5,5 };
	EXPECT_EQ(7, solution(in, 3));
}

TEST(task2, test2)
{
	std::vector<int> in{ 0 };
	EXPECT_EQ(1, solution(in, 1));
}

TEST(task2, test3)
{
	std::vector<int> in{ 0 };
	EXPECT_EQ(1, solution(in, 3));
}

TEST(task2, test4)
{
	std::vector<int> in{ 0,1,2,3,4,5,6 };
	EXPECT_EQ(1, solution(in, 0));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	std::cin.get();
}
