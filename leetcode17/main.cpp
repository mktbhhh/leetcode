//
// Created by mktb on 9/18/22.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    // vector<string> ans;
    //
    // unordered_map<char, vector<char>> buttonsMap = {
    //         {'2', {'a', 'b', 'c'}},
    //         {'3', {'d', 'e', 'f'}},
    //         {'4', {'g', 'h', 'i'}},
    //         {'5', {'j', 'k', 'l'}},
    //         {'6', {'m', 'n', 'o'}},
    //         {'7', {'p', 'q', 'r', 's'}},
    //         {'8', {'t', 'u', 'v'}},
    //         {'9', {'w', 'x', 'y', 'z'}}
    // };
    //
    // vector<string> letterCombinations(string digits) {
    //     ans = vector<string>{};
    //
    //     int len = digits.length();
    //     if (len == 0) {
    //         return ans;
    //     }
    //     dfs(0, len, digits, "");
    //
    //     return ans;
    // }
    //
    // void dfs(int now, int len, string digits, string str) {
    //     if (now == len) {
    //         ans.push_back(str);
    //         return;
    //     }
    //
    //     for (int i = 0; i < buttonsMap[digits[now]].size(); i++) {
    //         dfs(now + 1, len, digits, str + buttonsMap[digits[now]][i]);
    //     }
    // }

    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }
        unordered_map<char, string> phoneMap{
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };

        string combination;
        dfs(combinations, phoneMap, digits, 0, combination);

        return combinations;
    }

    void dfs(vector<string> &combinations, const unordered_map<char, string> &phoneMap, const string &digits, int index,
             string &combination) {
        if (index == digits.length()) {
            combinations.push_back(combination);
        } else {
            char digit = digits[index];
            const string &letters = phoneMap.at(digit);

            for (const char &letter: letters) {
                combination.push_back(letter);
                dfs(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};

TEST(Leetcode17Test, BasicTest) {
    Solution solution;

    string test1 = "23";
    vector<string> test1_result = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};

    string test2;
    vector<string> test2_result = {};

    string test3 = "2";
    vector<string> test3_result = {"a", "b", "c"};

    EXPECT_EQ(solution.letterCombinations(test1), test1_result);
    EXPECT_EQ(solution.letterCombinations(test2), test2_result);
    EXPECT_EQ(solution.letterCombinations(test3), test3_result);
}
