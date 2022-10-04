//
// Created by mktb on 9/19/22.
//
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len - 3; i++) {
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if ((long)nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < len - 2; j++) {
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long)nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target) {
                    continue;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int k = j + 1;
                int l = len - 1;

                while (k < l) {
                    long sum = (long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1]) {
                            k++;
                        }
                        k++;
                        while (k < l && nums[l] == nums[l - 1]) {
                            l--;
                        }
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};

TEST(Leetcode18Test, BasicTest) {
    Solution solution;

    vector<int> test1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<vector<int>> result1 = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};

    vector<int> test2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    vector<vector<int>> result2 = {{2, 2, 2, 2}};

    //EXPECT_EQ(solution.fourSum(test1, target1), result1);
    EXPECT_EQ(solution.fourSum(test2, target2), result2);
}
