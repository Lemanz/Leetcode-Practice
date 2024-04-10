/*
 * @Description: 课程表
 * @Autor: zsl
 * @Date: 2024-04-10 10:54:06
 * @LastEditors: zsl
 * @LastEditTime: 2024-04-10 13:35:37
 */
 #include <iostream>
 #include <vector>
 #include <queue>

 using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> incount(numCourses); // 入度
    vector<vector<int>> edges(numCourses); // 在索引课程后需要完成的课程
    for (auto pre : prerequisites) {
        incount[pre[0]]++;
        edges[pre[1]].push_back(pre[0]);
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (incount[i] == 0) {
            q.push(i);
        }
    }

    int visited = 0;
    while (!q.empty()) {
        int k = q.front(); 
        q.pop();
        visited++;
        
        for (auto num : edges[k]) {
            incount[num]--;
            if (incount[num] == 0) {
                q.push(num);
            }
        }
    }

    return visited == numCourses;
}

int main() {
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    int numCourses = 2;
    if (canFinish(numCourses, prerequisites)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}