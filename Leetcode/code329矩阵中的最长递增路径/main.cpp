/*
 * @Description: 矩阵中的最长递增路径
 * @Autor: zsl
 * @Date: 2024-04-10 09:58:55
 * @LastEditors: zsl
 * @LastEditTime: 2024-04-10 10:21:00
 */

#include <iostream>
#include <vector>

using namespace std;

int orients[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j, int m, int n) {
    
    if (memo[i][j] != 0) {
        return memo[i][j];
    }

    memo[i][j] ++; // 数字本身
    for (int k = 0; k < 4; k++) {
        int x = i + orients[k][0];
        int y = j + orients[k][1];
        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
            memo[i][j] = max(memo[i][j], dfs(matrix, memo, x, y, m, n) + 1); // 从该数字开始的最长递增路径长度
        }
    }

    return memo[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));

    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (memo[i][j] == 0) { // 判断是否计算过该数字
                res = max(res, dfs(matrix, memo, i, j, m, n));
            }
        }
    }
    return res;
}
int main() {
    vector<vector<int>> matrix = {{3,4,5},
                                  {3,2,6},
                                  {2,2,1}};

    cout << longestIncreasingPath(matrix) << endl;

    return 0;
}
