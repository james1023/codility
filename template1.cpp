/*
1. Equi
Find an index in an array such that its prefix sum equals its suffix sum.

This is a demo task.

A zero-indexed array A consisting of N integers is given. An equilibrium index of this array is any integer P such that 0 ≤ P < N and the sum of elements of lower indices is equal to the sum of elements of higher indices, i.e.
A[0] + A[1] + ... + A[P−1] = A[P+1] + ... + A[N−2] + A[N−1].
Sum of zero elements is assumed to be equal to 0. This can happen if P = 0 or if P = N−1.

For example, consider the following array A consisting of N = 8 elements:

A[0] = -1
A[1] =  3
A[2] = -4
A[3] =  5
A[4] =  1
A[5] = -6
A[6] =  2
A[7] =  1
P = 1 is an equilibrium index of this array, because:

A[0] = −1 = A[2] + A[3] + A[4] + A[5] + A[6] + A[7]
P = 3 is an equilibrium index of this array, because:

A[0] + A[1] + A[2] = −2 = A[4] + A[5] + A[6] + A[7]
P = 7 is also an equilibrium index, because:

A[0] + A[1] + A[2] + A[3] + A[4] + A[5] + A[6] = 0
and there are no elements with indices greater than 7.

P = 8 is not an equilibrium index, because it does not fulfill the condition 0 ≤ P < N.

Write a function:

int solution(vector<int> &A);

that, given a zero-indexed array A consisting of N integers, returns any of its equilibrium indices. The function should return −1 if no equilibrium index exists.

For example, given array A shown above, the function may return 1, 3 or 7, as explained above.

Assume that:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/

#include <limits.h>

#include <string>
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

bool will_addoverflow(int a, int b) {
	if (a > 0 && b > 0 && a > INT_MAX - b) return true;
	if (a < 0 && b < 0 && a < INT_MIN - b) return true;

	return false;
}

/*
[0]
[-1]
[1082132608, 0, 1082132608]
*/

int solution(std::vector<int> &A)
{

	return -1;
}

TEST(Equi, test0)
{
	std::vector<int> in{ 0 };
	EXPECT_EQ(-1, solution(in));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	std::cin.get();
}
