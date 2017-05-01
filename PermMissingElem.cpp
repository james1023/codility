#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <gtest/gtest.h>

using namespace std;

int solution(vector<int> &A) 
{
	// write your code in C++11 (g++ 4.8.2)
	int res = 0;

	for (int i = 0; i < int(A.size()); i++) {
		res += (i + 1 - A[i]);
	}

	res += int(A.size() + 1);

	return res;
}

TEST(PermMissingElem, test0)
{
	std::vector<int> in{ 2, 3, 1, 5 };
	EXPECT_EQ(4, solution(in));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	std::cin.get();
}
