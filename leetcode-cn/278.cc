// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


```
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // 跳出条件是 low > high, 即 low = high + 1
        // mid isBadVersion, 那么(high = mid -1) is not isBadVersion
        // (high = mid -1) +１即low 为isBadVersion
        return low;
    }
};