/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros 
that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. 
The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. 
The number 20 has binary representation 10100 and contains one binary gap of length 1.
The number 15 has binary representation 1111 and has no binary gaps.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 
and so its longest binary gap is of length 5.
*/

#include <stdio.h>

#include <gtest/gtest.h>

int solution(int N);
int solution(int N)
{
	// write your code in C++11 (g++ 4.8.2)
	int zeros = -1;
	int max_gap = 0;

	while (N > 0) {
		if ((N & 1) == 1) {
			zeros = 0;
		}
		else if (zeros != -1) {
			zeros++;
			if (max_gap < zeros) {
				max_gap = zeros;
			}
		}

		N = N >> 1;
	}

	return max_gap;
}

TEST(BinaryGap, test1)
{
	printf("%d\n", solution(9));
	printf("%d\n", solution(20));
	printf("%d\n", solution(15));

	EXPECT_EQ(0, 0);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	getchar();
}
