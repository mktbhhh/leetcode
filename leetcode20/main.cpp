//
// Created by mktb on 10/12/22.
//

#include <gtest/gtest.h>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> leftStack;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            char ch = s.at(i);
            if (ch == '(' || ch == '{' || ch == '[') {
                leftStack.push(ch);
            }
            if (ch == ')' || ch == '}' || ch == ']') {
                if (leftStack.empty()) {
                    return false;
                }
                char top = leftStack.top();
                leftStack.pop();

                if (ch == ')' && top != '(') {
                    return false;
                }
                if (ch == '}' && top != '{') {
                    return false;
                }
                if (ch == ']' && top != '[') {
                    return false;
                }
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
    EXPECT_EQ(solution.isValid(test1), true);
    EXPECT_EQ(solution.isValid("()[]{}"), true);
    EXPECT_EQ(solution.isValid("(]"), false);
}
