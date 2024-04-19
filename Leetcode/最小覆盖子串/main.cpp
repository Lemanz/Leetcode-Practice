/*
 * @Description: 最小覆盖子串
 * @Autor: PT Uncle 紫薯叔
 * @Date: 2024-04-19 10:59:42
 * @LastEditors: zsl
 * @LastEditTime: 2024-04-19 11:17:57
 */
#include <iostream>
#include <unordered_map>
#include <string>


using namespace std;

 string minWindow(string s, string t) {
    unordered_map<char, int> mps, mpt;
    for (auto c : t) {
        mpt[c]++;
    }
    
    int left = 0, right = 0, valid = 0, start = 0, minlen = INT_MAX;
    while (right < s.size()) {
        char c = s[right];
        if (mpt.count(c) > 0) {
            mps[c]++;
            if (mps[c] == mpt[c]) {
                valid++;
            }
        }
        right++;

        while (valid == mpt.size()) {
            if (right - left < minlen) {
                start = left;
                minlen = right - left;
            }

            char c = s[left];
            left++;
            if (mpt.count(c) > 0 && mps[c] > 0) {
                if (mpt[c] == mps[c]) {
                    valid--;
                }
                mps[c]--;
            }
        }
    }
    return minlen == INT_MAX ? "" : s.substr(start, minlen);
 }

 int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;

    return 0;
 }