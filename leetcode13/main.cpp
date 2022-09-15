//
// Created by mktb on 8/25/22.
//

#include <gtest/gtest.h>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<char, int> symbolValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

public:
    int romanToInt(std::string s) {
        int res = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                res -= value;
            } else {
                res += value;
            }
        }

        return res;
    }
};

// Demonstrate some basic assertions.
TEST(Leetcode13Test, BasicTest) {
    Solution solution;
    EXPECT_EQ(solution.romanToInt("III"), 3);
    EXPECT_EQ(solution.romanToInt("LVIII"), 58);
}

// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
