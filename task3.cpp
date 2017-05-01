
#include <limits.h>

#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <locale>

#include <stack> 

#include <gtest/gtest.h>

using namespace std;

bool is_number(string str)
{
	string::iterator it = str.begin();
	if (*it == '0' && str.length() > 1)
		return false;

	for (; it < str.end(); it++) {
		if (*it <'0' || *it > '9')
			return false;
	}
	return true;
}

int solution(string &S) {
	std::locale loc;
	std::stack<int> stack;

	char *token;
	char *str = strdup(S.c_str());

	token = strtok(str, " ");
	int num = 0;
	int a = 0, b = 0;
	while (token != NULL) {
		if (isdigit(token[0], loc)) {
			num = atoi(token);
			stack.push(num);
		}
		else {
			if (0 == strcmp(token, "DUP")) {
				stack.push(stack.top());
			}
			else if (0 == strcmp(token, "POP")) {
				stack.pop();
			}
			else if (0 == strcmp(token, "+")) {
				a = stack.top(); stack.pop();
				if (stack.empty()) return -1;
				b = stack.top(); stack.pop();
				stack.push(a + b);
			}
			else if (0 == strcmp(token, "-")) {
				a = stack.top(); stack.pop();
				if (stack.empty()) return -1;
				b = stack.top(); stack.pop();
				stack.push(a - b);
			}
		}

		token = strtok(NULL, " ");
	}
	free(str);

	return stack.top();
}

TEST(task3, test0)
{
	std::string S = "13rr DUP 4 POP 5 DUP + DUP + -";
	EXPECT_EQ(7, solution(S));
}

TEST(task3, test1)
{
	std::string S = "5 6 + -";
	EXPECT_EQ(7, solution(S));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	std::cin.get();
}
