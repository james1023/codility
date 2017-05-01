#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
//#include <unordered_map>

#include <gtest/gtest.h>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	// write your code in C++11 (g++ 4.8.2)
	vector<int> pre_sum_A;
	vector<int> pre_sum_C;
	vector<int> pre_sum_G;
 
	int cnt_A = 0;
	int cnt_C = 0;
	int cnt_G = 0;
 
	for (size_t i = 0; i < S.size(); i++) {
		if (S[i] == 'A') cnt_A++;
		else if (S[i] == 'C') cnt_C++;
		else if (S[i] == 'G') cnt_G++;
 
		pre_sum_A.push_back(cnt_A);
		pre_sum_C.push_back(cnt_C);
		pre_sum_G.push_back(cnt_G);
	}
 
	vector<int> result(P.size());
	for (int i = 0; i < int(P.size()); i++) {
		int A = (S[P[i]] == 'A') ? 1 : 0;
		int C = (S[P[i]] == 'C') ? 1 : 0;
		int G = (S[P[i]] == 'G') ? 1 : 0;

		if (pre_sum_A[Q[i]] - pre_sum_A[P[i]] + A > 0) result[i] = 1;
		else if (pre_sum_C[Q[i]] - pre_sum_C[P[i]] + C > 0) result[i] = 2;
		else if (pre_sum_G[Q[i]] - pre_sum_G[P[i]] + G > 0) result[i] = 3;
		else result[i] = 4;
	}
 
	return result;
}

/*
struct Results {
    int *A;
    int M;
};

struct Results solution(char *S, int P[], int Q[], int M)
{
    unsigned length = strlen(S);
    int A[length], C[length], G[length], T[length];

    for (int i = 0; i < length; ++i) {
        if (i == 0)
            A[i] = C[i] = G[i] = T[i] = 0;
        else {
            A[i] = A[i - 1];
            C[i] = C[i - 1];
            G[i] = G[i - 1];
            T[i] = T[i - 1];
        }
        switch (S[i]) {
            case 'A':
                ++A[i];
                break;
            case 'C':
                ++C[i];
                break;
            case 'G':
                ++G[i];
                break;
            case 'T':
                ++T[i];
                break;
        }
    }

    struct Results result = {calloc(M, sizeof(int)), M};
    for (int i = 0; i < M; ++i) {
        if (A[Q[i]] - (P[i] > 0 ? A[P[i] - 1] : 0) > 0)
            result.A[i] = 1;
        else if (C[Q[i]] - (P[i] > 0 ? C[P[i] - 1] : 0) > 0)
            result.A[i] = 2;
        else if (G[Q[i]] - (P[i] > 0 ? G[P[i] - 1] : 0) > 0)
            result.A[i] = 3;
        else
            result.A[i] = 4;
    }
    return result;
}
*/

TEST(GenomicRangeQuery, test0)
{
	std::string S = "GACACCATA";
	std::vector<int> P{ 0, 0, 4, 7 };
	std::vector<int> Q{ 8, 2, 5, 7 };

	solution(S, P, Q);

	EXPECT_EQ(0, 0);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	std::cin.get();

    /*char S[] = "CAGCCTA";
    int P[] = {2, 5, 0}, Q[] = {4, 5, 6};
    struct Results result = solution(S, P, Q, 3);
    for (int i = 0; i < 3; ++i)
        printf("%d ", result.A[i]);
    puts("");*/

    return 0;
}
