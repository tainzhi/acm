class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stack;
        for (int i = 0; i < 2 * n; i++) {
            while (!stack.empty() && (nums[i % n] > nums[stack.top()])) {
                auto t = stack.top();
                stack.pop();
                res[t] = nums[i % n];
            }
            stack.push(i % n);
        }
        return res;
    }
};