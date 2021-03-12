class Solution {
private:
    const int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCnt = 0;
        int n = grid.size(), m =grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<int, int>> Q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++freshCnt;
                } else if (grid[i][j] == 2) {
                    Q.push(make_pair(i, j));
                }
            }
        }
        int ans = 0;
        while (!Q.empty()) {
            auto current = Q.front();
            Q.pop();
            int x = current.first, y = current.second;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1)
                    continue;
                --freshCnt;
                grid[nx][ny] = 2;
                dist[nx][ny] = dist[x][y] + 1;
                Q.push(make_pair(nx, ny));
            }
            ans = std::max(ans, dist[x][y]);
        }
        return freshCnt == 0 ? ans : -1;
    }
};