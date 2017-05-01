
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

bool swap(int *a, int *b)
{
	int temp;
	if (*a > *b) {
		temp = *a;
		*a = *b;
		*b = temp;

		return true;
	}
	
	return false;
}

void quicksort(vector<int> &data, int left, int right, int &swap_ct)
{
	int pivot, i, j;

	if (swap_ct > 1) return;
	if (left >= right) { return; }

	pivot = data[left];

	i = left + 1;
	j = right;

	while (1) {
		while (i <= right) {
			if (data[i] > pivot) {
				break;
			}

			i = i + 1;
		}

		while (j > left) {
			if (data[j] < pivot) {
				break;
			}

			j = j - 1;
		}

		if (i > j) { break; }

		if (true == swap(&data[i], &data[j])) {
			swap_ct++;
			if (swap_ct > 1) return;
		}
	}

	if (true == swap(&data[left], &data[j])) {
		swap_ct++;
		if (swap_ct > 1) return;
	}

	quicksort(data, left, j - 1, swap_ct);
	quicksort(data, j + 1, right, swap_ct);
}

bool solution(vector<int> &A)
{
	int swap_ct = 0;
	int size = A.size();

	if (size <= 1) return true;

	quicksort(A, 0, size -1, swap_ct);

	if (swap_ct > 1) return false;

	return true;
}

TEST(task1, test0)
{
	std::vector<int> in{ 1, 5, 3, 3, 7 };
	EXPECT_EQ(true, solution(in));
}

TEST(task1, test1)
{
	std::vector<int> in{ 1 };
	EXPECT_EQ(false, solution(in));
}

TEST(task1, test2)
{
	std::vector<int> in{ 1, 1000000000, 5 };
	EXPECT_EQ(true, solution(in));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	std::cin.get();
}
