//
// Created by mktb on 9/11/22.
//

#include <gtest/gtest.h>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector <std::string> &strs) {
        int max = strs[0].length();
        std::string base = strs[0];

        for (std::vector<std::string>::iterator iter = strs.begin() + 1; iter != strs.end(); iter++) {
            int n_max = 0;
            for (int i = 0; i < (*iter).length(); i++) {
                if (base[i] == (*iter)[i]) {
                    n_max++;
                } else {
                    break;
                }
            }
            if (n_max < max) {
                max = n_max;
            }
        }

        return base.substr(0, max);
    }
};

// Demonstrate some basic assertions.
TEST(Leetcode14Test, BasicTest) {
    Solution solution;
    std::vector<std::string> test1_vector = {"flower", "flow", "flight"};
    std::vector<std::string> test2_vector = {"dog", "racecar", "car"};
    EXPECT_EQ(solution.longestCommonPrefix(test1_vector), "fl");
    EXPECT_EQ(solution.longestCommonPrefix(test2_vector), "");
}

// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
