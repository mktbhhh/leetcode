//
// Created by mktb on 10/5/22.
//
#include <gtest/gtest.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;

        for (int i = 0; i < n - 1; i++) {
            end = end->next;
        }

        ListNode* p = head;
        ListNode* pre = head;
        while (end->next != nullptr) {
            pre = p;
            end = end->next;
            p = p->next;
        }

        if (p == head) {
            return head->next;
        }
        pre->next = p->next;
        delete p;
        return head;
    }

    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;

        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        while (first) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

void destoryListNode(ListNode* head) {
    ListNode* p = head;
    while (p != nullptr) {
        head = p;
        p = p->next;
        delete head;
    }
}

TEST(Leetcode19Test, BasicTest) {
    Solution solution;

    ListNode* test1 = new ListNode(1, new ListNode(2,  new ListNode(3,  new ListNode(4,  new ListNode(5)))));
    int target1 = 2;
    ListNode* result1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(5))));

    ListNode* test2 = new ListNode(1);
    int target2 = 1;
    ListNode* result2 = new ListNode();

    ListNode* test3 = new ListNode(1, new ListNode(2));
    int target3 = 1;
    ListNode* result3 = new ListNode(1);

    //EXPECT_EQ(solution.fourSum(test1, target1), result1);
    result1 = solution.removeNthFromEnd(test1, 2);
    result2 = solution.removeNthFromEnd(test2, 1);
    result3 = solution.removeNthFromEnd(test3, 1);

    destoryListNode(test1);
    destoryListNode(test2);
    destoryListNode(test3);
}
