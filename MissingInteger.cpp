#include <set>
#include <vector>
#include <iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*int solution(std::vector<int> &A) {
	// write your code in C++11
	int N = A.size();
	std::vector <int> counter(N + 1);

	// count the numbers
	for (int i = 0; i < N; i++) {
		if (A[i] > 0 && A[i] <= N + 1) {
			// counting the number we meet
			counter[A[i] - 1] = 1;
		}
	}

	for (int i = 0; i < N + 1; i++) {
		if (!(counter[i])) return i + 1;
	}

	// compiler shouldnt reach here
	return -1;
}*/

int solution(std::vector<int> &A) {
	// write your code in C++11
	int N = A.size();
	std::set<int>save_item;

	for (int i = 0; i < N; i++) {
		if (A[i] >= 0 && A[i] <= N + 1) {
			save_item.insert(A[i]);
		}
	}

	int last_value = 0;
	for (std::set<int>::iterator iter = save_item.begin(); iter != save_item.end(); iter++) {
		if (++last_value != *iter)
			return (last_value);
	}

	if (last_value >= 0) return last_value + 1;

	return -1;
}

int main(void)
{
	std::vector<int> A{ -1 };
	
	std::cout << solution(A) << std::endl;

	std::cin.get();
}