class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int gi = 0, si = 0;
        while (gi < g.size() && si < s.size()) {
            if (g[gi] <= s[si]) {
                // 已经满足了一个小孩
                gi++;
            }
            // 最小的饼干都不能满足, 所以要丢弃(si++)
            si++;
        }
        return gi;
    }
};