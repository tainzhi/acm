class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int begin = matrix[0][0], end = matrix[row-1][col-1], mid;
        while (begin <= end) {
            mid = begin + (end - begin) /2;
            int cnt = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col && matrix[i][j] <= mid; j++) {
                    cnt++;
                }
            }
            if (cnt < k) begin = mid+1;
            else end = mid - 1;
        }
        return begin;
    }
};