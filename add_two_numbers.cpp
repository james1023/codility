#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>

#include <gtest/gtest.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode *head1_node_ = NULL;
struct ListNode *head2_node_ = NULL;
struct ListNode *head3_node_ = NULL;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *head = NULL, *prev = NULL;
	int carry = 0;
	while (l1 || l2) {
		int v1 = l1 ? l1->val : 0;
		int v2 = l2 ? l2->val : 0;
		int tmp = v1 + v2 + carry;
		carry = tmp / 10;
		int val = tmp % 10;
		ListNode *cur = new ListNode(val);
		if (!head) head = cur;
		if (prev) prev->next = cur;
		prev = cur;
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}
	if (carry > 0) {
		ListNode* l = new ListNode(carry);
		prev->next = l;
	}
	return head;
}

TEST(addTwoNumbers, addTwoNumbers_1)
{
	head3_node_ = addTwoNumbers(head1_node_, head2_node_);
	// for (int i = 0; i < 1000000000; i++) {}
	
    EXPECT_EQ(0, 0);
}

struct ListNode *CreateLinklist(std::vector<int> &in)
{
	struct ListNode *head_node = NULL, *ptr_node = NULL, *new_node = NULL;

	for (int i = 0; i < in.size(); i++) {
		if (0 == head_node) {
			head_node = (struct ListNode *)malloc(sizeof(struct ListNode));
			head_node->val = in[i];
			head_node->next = NULL;
			ptr_node = head_node;
		}
		else {
			new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
			new_node->val = in[i];
			new_node->next = 0;
			ptr_node->next = new_node;
			ptr_node = new_node;
		}
	}

	return head_node;
}

void FreeLinkList(struct ListNode *head_node)
{
	struct ListNode *ptr_node = NULL;

	while (head_node != NULL) {
		ptr_node = head_node;
		head_node = head_node->next;
		free(ptr_node);
	}
}

void PrintLinkList(struct ListNode *head_node)
{
	struct ListNode *ptr_node = head_node;

	std::cout << "answer = ";
	while (ptr_node != NULL) {
		std::cout << ptr_node->val << std::setw(4);
		ptr_node = ptr_node->next;
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	std::vector<int> s1{ 8, 4, 3 };
	std::vector<int> s2{ 8, 6, 4 };

	head1_node_ = CreateLinklist(s1);
	head2_node_ = CreateLinklist(s2);

    testing::InitGoogleTest(&argc, argv);
    
    RUN_ALL_TESTS();

	PrintLinkList(head3_node_);

	FreeLinkList(head1_node_);
	FreeLinkList(head2_node_);
	FreeLinkList(head3_node_);

    std::cin.get();

    return 1;
}