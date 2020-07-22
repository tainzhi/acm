class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size() - 1, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (numbers[mid] > numbers[high]) {
                low = mid + 1;
            } else if (numbers[mid] < numbers[high]) {
                high = mid;
            } else {
                high = high - 1;
            }
        }
        return numbers[high];
    }
};