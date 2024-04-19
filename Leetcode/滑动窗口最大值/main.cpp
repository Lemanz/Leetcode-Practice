/*
 * @Description: 滑动窗口最大值
 * @Autor: PT Uncle 紫薯叔
 * @Date: 2024-04-19 10:43:12
 * @LastEditors: zsl
 * @LastEditTime: 2024-04-19 10:58:10
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res;
    deque<int> q; // 采用双端队列
    for (int i = 0; i < k; i++) {
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    res.push_back(nums[q.front()]);

    for (int i = k; i < n; i++) {
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        q.push_back(i);

        while (!q.empty() && i - q.front() >= k) {
            q.pop_front();
        }
        res.push_back(nums[q.front()]);
    }
    return res;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for (auto num : res) {
        cout << num << " ";
    }
    return 0;
}