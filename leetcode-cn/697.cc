class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> nmap;
        map<int, int> left;
        map<int, int> right;
        vector<int> maxCountNums;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = nums[i];
            // 为了区分left[cnt] = i为0 与map初始化为0, 把所有的位置+1 
            if (left[cnt] == 0) left[cnt] = i +1;
            right[cnt] = i +1;
            nmap[cnt]++;
            if (nmap[cnt] >= maxCount) {
                if (nmap[cnt] > maxCount) {
                    maxCountNums.clear();
                }
                maxCount = nmap[cnt];
                maxCountNums.push_back(cnt);
            }
        }
        int minLength = INT_MAX;
        for (auto num: maxCountNums) {
            minLength = std::min(minLength, right[num] - left[num] + 1);
        }
        return minLength;
    }
};