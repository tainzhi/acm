class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (auto i: nums) {
            single ^= i;
        }
        return single;
    }
};