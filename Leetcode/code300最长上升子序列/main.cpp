/*
 * @Description: Leetcode300-最长递增子序列
 * @Autor: zsl
 * @Date: 2024-04-09 16:30:57
 * @LastEditors: zsl
 * @LastEditTime: 2024-04-09 17:55:54
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int lengthOfLIS(vector<int>& nums) {
    int res = 0;
    int len = nums.size();
    if (len == 1) {
        return 1;
    }

    vector<int> dp(len, 1);
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums) << endl;

    return 0;
}