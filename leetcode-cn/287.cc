class Solution {
public:
    // 快慢指针法
    // 有相同的值, 一定会形成像环一样
    int findDuplicate1(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int ptr1 = nums[0];
        int ptr2 = slow;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }

    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size(), mid, cnt;
        while (low <= high) {
            mid = low + (high - low) >> 1;
            cnt = 0;
            for (auto i: nums) {
                if (i <=nums[mid]) {
                    cnt++;
                }
            }
            if (cnt > mid) {
                low = mid +1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};