/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int originalTarget = target;
        for (int a = 0; a < nums.size(); ++a) {
            if (a != 0 && nums[a] == nums[a - 1]) continue;
            for (int b = a + 1; b < nums.size(); ++b) {
                if (b != (a + 1) && nums[b] == nums[b - 1]) continue;
                int c = b + 1, d = nums.size() - 1;
                target = originalTarget - nums[a] - nums[b];
                int preCVal = INT_MIN, preDVal = INT_MIN;
                while (c < d) {
                    int cur = nums[c] + nums[d];
                    if (cur == target) {
                        if (preCVal != nums[c] || preDVal != nums[d]) {
                            preCVal = nums[c];
                            preDVal = nums[d];
                            ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        }
                        ++c;
                        --d;
                    } else if (cur > target) {
                        --d;
                    } else if (cur < target) {
                        ++c;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

