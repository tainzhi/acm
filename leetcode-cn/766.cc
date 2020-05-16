class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();

        // 对角线右边
        for (int i = 0; i < c; i++) {
            if (!isSameRight(matrix, i, r, c)) {
                return false;
            }
        }
        for (int j = 1; j < r; j++) {
            if (!isSameLeft(matrix, j, r, c)) {
                return false;
            }
        }
        return true;
    }

    bool isSameLeft(vector<vector<int>>& matrix, int ir, int r, int c) {
        int ic =1;
        ir++;
        while (ir < r && ic <c) {
            if (matrix[ir][ic] != matrix[ir-1][ic-1]) {
                return false;
            }
            ir++;
            ic++;
        }
        return true;
    }

    bool isSameRight(vector<vector<int>>& matrix, int ic, int r, int c) {
        int ir = 1;
        ic++;
        while (ir < r && ic <c) {
            if (matrix[ir][ic] != matrix[ir-1][ic-1]) {
                return false;
            }
            ir++;
            ic++;
        }
        return true;
    }
};