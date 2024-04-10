/*
 * @Description: 零钱兑换
 * @Autor: PT Uncle 紫薯叔
 * @Date: 2024-04-10 09:32:31
 * @LastEditors: zsl
 * @LastEditTime: 2024-04-10 13:42:36
 */

#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (auto coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 11) << endl;

    return 0;
}

