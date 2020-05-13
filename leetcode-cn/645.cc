class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size() + 1;
        int tag[n];
        std::fill_n(tag, n, 0);
        vector<int> result;
        for (auto i: nums) {
            tag[i]++;
            if (tag[i] > 1) {
                result.push_back(i);
            }
        }
        for (int i = 1; i < n; ++i) {
            if (tag[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};