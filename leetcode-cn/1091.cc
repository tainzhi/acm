struct node
{
    int y;
    int x;
};
class Solution
{
private:
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        queue<node> q;
        int m = grid.size();    // y轴
        int n = grid[0].size(); // x轴

        vector<vector<int>> direction_eight = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
        {
            return -1;
        }

        // 标记已经访问; 初始, 0, 未访问
        vector<vector<int>> mem(m, vector<int>(n, 0));
        q.push({0, 0});
        int ans = 0;
        mem[0][0] = 1;
        while (!q.empty())
        {
            int q_size= q.size();
            for (int i = 0; i < q_size; ++i)
            {
                auto current_n = q.front();
                int y = current_n.y, x = current_n.x;
                if (x == (n - 1) && y == (m - 1))
                {
                    return ans + 1;
                }
                for (auto d : direction_eight)
                {
                    int n_y = y + d[0], n_x= x + d[1];
                    // 边界检查
                    if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m)
                        continue;
                    // 不能访问检查
                    if (grid[n_y][n_x] == 1)
                        continue;
                    // 备忘录检查
                    if (mem[n_y][n_x] == 1)
                        continue;
                    q.push({n_y, n_x});
                    mem[n_y][n_x] = 1;
                }
                q.pop();
            }
            ans++;
        }
        return -1;
    }
};