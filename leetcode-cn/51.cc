class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // 记录queue位置, i表示第i行放置的queue在queuePosition[i]列
        int queuePosition[n];
        std::fill_n(queuePosition, n, -1);
        vector<vector<string>> result;
        backTrace(n, 0, queuePosition, result);
        return result;
    }

    void backTrace(int n, int indexRow, int *queuePosition, vector<vector<string>> &result) {
        if (indexRow == n) {
            printToMatrix(result, n, queuePosition);
        }
        for (int i = 0; i < n; i++) {
            if (queuePositionValid(queuePosition, n, indexRow, i)) {
                queuePosition[indexRow] = i;
                backTrace(n, indexRow + 1, queuePosition, result);
                queuePosition[indexRow] = -1;
            }
        }
    }

    void printToMatrix(vector<vector<string>> &result, int n, int * queuePosition) {
        vector<string> track;
        for (int i = 0; i < n; i++) {
            string row(n, '.');
            row[queuePosition[i]] = 'Q';
            track.push_back(row);
        }
        result.push_back(track);
    }

    bool queuePositionValid(int * queuePosition, int n, int row, int col) {
        for (int i = 0; i < n; i++) {
            if (queuePosition[i] != -1) {
                // 同一列
                if (i == row) return false;
                // 同一行
                if (queuePosition[i] == col) return false;
                // 在一条斜线上, abs(x1 - x2) == abs(y1 - y2)
                if (std::abs(i - row) == std::abs(queuePosition[i] - col)) {
                    return false;
                }
            }
        }
        return true;
    }
};