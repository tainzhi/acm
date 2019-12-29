class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            quickSort(nums, 0, nums.size() - 1);
            return nums;

        }
        void quickSort(vector<int>&nums, int low, int high) {
            if (low >= high) return;
            int i = low, j = high + 1;
            int pivot = nums[i];
            while (true) {
                while (nums[++i] < pivot) {
                    if (i == high) break;
                }
                while (nums[--j] > pivot) {
                    if (j == low) break;
                }
                if (i >= j) break;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            int temp = nums[low];
            nums[low] = nums[j];
            nums[j] = temp;
            quickSort(nums, low, j-1);
            quickSort(nums, j+1, high);
        }

};
