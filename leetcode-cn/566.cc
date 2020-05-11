class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() == 0 && r * c != 0) return nums;
        if (nums.size() * nums[0].size() != r * c) return nums;
        vector<vector<int>> result(r, vector<int>(c));
        int oi = 0, oj = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                result[i][j] = nums[oi][oj];
                ++oj;
                if (oj == nums[0].size()) {
                    oj = 0;
                    ++oi;
                }
            }
        }
        return result;
    }
};