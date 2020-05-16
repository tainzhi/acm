class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int currentMax = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            currentMax = std::max(currentMax, arr[i]);
            if (currentMax == i) {
                count++;
            }
        }
        return count;
    }
};