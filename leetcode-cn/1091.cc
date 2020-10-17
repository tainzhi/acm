class Solution {
private:
    int shortestLen = INT_MAX;
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int step) {
        if ( i >= 0 && i < grid[0].size() && j >= 0 && j < grid[0].size() ) {
            if (grid[i][j] == 1) return;
            if (i == grid[0].size() +  - 1 && j == grid[0].size() - 1) {
                shortestLen = std::min(shortestLen, step);
            } else {
                dfs(grid, i + 1, j, step + 1);
                dfs(grid, i + 1, j + 1, step + 1);
                dfs(grid, i, j + 1, step + 1);
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        dfs(grid, 0, 0, 1);
        if (shortestLen < INT_MAX) {
            return shortestLen;
        } else {
            return -1;
        }
    }
};