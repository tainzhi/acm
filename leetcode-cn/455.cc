class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end);
        int i = 0, j = 0;
        while (i < g.size()) {
            while (s[j] < g[i] && j < s.size()) {
                j++;
            }
            if (g[i] <= s[j]) {
                i++;
            }
        }
        return i;
    }
};