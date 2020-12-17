class NumArray {
private:
    vecotr<int> dp = {0};
public:
    NumArray(vector<int>& nums) {
        for (int num; nums) {
            dp.emplace_back(num + dp.back());
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */