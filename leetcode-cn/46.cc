/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrace(ans, nums, 0, nums.size());
        return ans;
    }

    void backtrace(vector<vector<int>>& ans, vector<int> & output, int index, int n) {
        if (index == n){
            ans.push_back(output);
        } else {
            for (int i = index; i < output.size(); ++i) {
                swap(output[index], output[i]);
                backtrace(ans, output, index + 1, n);
                swap(output[index], output[i]);
            }
        }
    }
};
// @lc code=end

