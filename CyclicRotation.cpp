#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>

#include <gtest/gtest.h>

std::vector<int> solution(std::vector<int> &A, int K) 
{
	// write your code in C++11 (g++ 4.8.2)
	if (A.size() == 0) return A;
	K = K % A.size();
	if (K == 0) return A;

	std::vector<int> res(A.size());

	const int size1 = int(A.size() - K);

	for (int i = 0; i < size1; i++) {
		res[i + K] = A[i];
	}

	for (int i = size1; i < int(A.size()); i++) {
		res[i - size1] = A[i];
	}

	return res;
}

std::vector<int> j_solution(std::vector<int> &A, int K)
{
	if (A.size() == 0) return A;
	int u = K % A.size();
	if (u == 0) return A;

	std::vector<int> B(A.size());

	const int pt = (int)(A.size() - K);

	for (int i = 0; i < pt; i++) {
		B[i + K] = A[i];
	}

	for (int i = size1; i < A.size(); i++) {
		B[i - size1] = A[i];
	}

	return B;
}

std::vector<int> out_;
TEST(CyclicRotation, test1)
{
	std::vector<int> in{ -1, 6, 8, 90, -6, 4, 6, -345, 7, 7 };

	out_ = solution(in, 55);

	EXPECT_EQ(0, 0);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	for (int i = 0; i < out_.size(); i++) {
		std::cout << out_[i] << std::setw(4);
	}
	std::cout << std::endl;

	std::cin.get();
}