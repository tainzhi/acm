class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 0, high = A.size(), mid ;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (A[mid] < A[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};