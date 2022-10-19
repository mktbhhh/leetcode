//
// Created by mktb on 10/14/22.
//

#include <gtest/gtest.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *ansp = new ListNode();
        ListNode *now = ansp;
        ListNode *next = ansp;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                now->next = list2;
                list2 = list2->next;
            } else {
                now->next = list1;
                list1 = list1->next;
            }

            now = now->next;
        }

        now->next = list1 == nullptr ? list2 : list1;

        ListNode *ans = ansp->next;
        delete ansp;
        return ans;
    }
};

void destoryListNode(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr) {
        head = p;
        p = p->next;
        delete head;
    }
}

TEST(Leetcode21Test, BasicTest) {
    Solution solution;

    ListNode *test11 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *test12 = new ListNode(1, new ListNode(3, new ListNode(4)));

    solution.mergeTwoLists(test11, test12);

    destoryListNode(test11);
}
