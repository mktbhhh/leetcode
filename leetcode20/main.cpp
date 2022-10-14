//
// Created by mktb on 10/12/22.
//

#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {
                {')', '('},
                {']', '['},
                {'}', '{'}
        };

        stack<char> leftStack;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            char ch = s.at(i);
            if (pairs.count(ch)) {
                if (leftStack.empty() || leftStack.top() != pairs[ch]) {
                    return false;
                }
                leftStack.pop();
            } else {
                leftStack.push(ch);
            }
        }

        if (leftStack.empty()) {
            return true;
        }
        return false;
    }
};

TEST(Leetcode20Test, BasicTest) {
    Solution solution;

    string test1 = "()";
    // EXPECT_EQ(solution.isValid(test1), true);
    EXPECT_EQ(solution.isValid("()[]{}"), true);
    // EXPECT_EQ(solution.isValid("(]"), false);
}
