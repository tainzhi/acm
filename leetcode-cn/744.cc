class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            mid = low  + (high - low) / 2;
            if (letters[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // mid是小于target的, 那么low = mid + 1符合要求, 同时也跳出了循环
        return low < n ? letters[low] : letters[0];
    }
};