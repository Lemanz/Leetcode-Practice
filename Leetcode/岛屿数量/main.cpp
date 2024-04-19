/*
 * @Description: 岛屿数量
 * @Autor: zsl
 * @Date: 2024-04-10 10:24:16
 * @LastEditors: zsl
 * @LastEditTime: 2024-04-10 10:52:17
 */

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
        return;
    }
    if (grid[i][j] == '1') {
        grid[i][j] = '2';
    }

    dfs(grid, i+1, j, m, n);
    dfs(grid, i-1, j, m, n);
    dfs(grid, i, j+1, m, n);
    dfs(grid, i, j-1, m, n);
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, m, n);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0'},
        {'0', '0', '1'},
        {'0', '0', '1'}
    };

    cout << numIslands(grid) << endl;

    return 0;
}