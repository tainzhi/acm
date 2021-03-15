/*
 * @lc app=leetcode.cn id=1163 lang=cpp
 *
 * 字典序最大的一定是后缀数组
 * 比如 abcdeab
 * 最大的一定是 eab
 * 双指针
 */

// @lc code=start
class Solution {
public:
    string lastSubstring(string s) {
        if (s.size() < 2) return s;
        long long left = 0, right = left + 1, step = 0;
        while (right + step < s.size()) {
            if (s[left + step] == s[right + step] && left + step <= right) {
                ++step;
            }
            else if (s[left + step] < s[right + step]) {
                left = right;
                right = left + 1;
                step = 0;
            } else {
                right += step + 1;
                step = 0;
            }
        }
        return s.substr(left);
    }
};
// @lc code=end

