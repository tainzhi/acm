/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int index = 0;
        for (int nu: pushed) {
            st.push(nu);
            while (index < popped.size() && !st.empty() && st.top() == popped[index]) {
                ++index;
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

