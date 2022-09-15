//
// Created by mktb on 9/15/22.
//
#include <vector>
#include <gtest/gtest.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosestHanhan(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1000000;

        for (int first = 0; first < n; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }

            int third = n - 1;
            int tar = target - nums[first];

            for (int second = first + 1; second < n; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // abs(nums[second] + nums[third] - tar) > abs(ans - target)
                while (second < third && nums[second] + nums[third] - tar > 0) {
                    if (abs(nums[second] + nums[third] - tar) < abs(ans - target)) {
                        ans = nums[first] + nums[second] + nums[third];
                    }
                    --third;
                }

                if (second == third) {
                    break;
                }

                if (abs(nums[second] + nums[third] - tar) < abs(ans - target)) {
                    ans = nums[first] + nums[second] + nums[third];
                }
            }
        }

        return ans;
    }

    int threeSumClosest(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int best = 1e7;

        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                }
                update(sum);

                if (sum > target) {
                    int k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k0 + 1]) {
                        k0--;
                    }
                    k = k0;
                } else {
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j0 - 1]) {
                        j0++;
                    }
                    j = j0;
                }
            }
        }

        return best;
    }

    int threeSumClosestTest(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int best = 1e7;

        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };

        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                }
                update(sum);

                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return best;
    }
};

// Demonstrate some basic assertions.
TEST(Leetcode16Test, BasicTest) {
    Solution solution;

    vector<int> test1_vector = {-1, 2, 1, -4};
    vector<int> test2_vector = {0, 0, 0};
    vector<int> test3_vector = {4,0,5,-5,3,3,0,-4,-5};

    EXPECT_EQ(solution.threeSumClosestTest(test1_vector, 1), 2);
    EXPECT_EQ(solution.threeSumClosestTest(test2_vector, 1), 0);
    EXPECT_EQ(solution.threeSumClosestTest(test3_vector, -2), -2);
}
