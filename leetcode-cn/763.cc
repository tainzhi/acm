class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        map<char, int> index;
        for (int i = 0; i < S.size(); i++)
        {
            index[S[i]] = i;
        }
        vector<int> ret;
        int anchor = 0, start = 0;
        for (int i = 0; i < S.size(); i++)
        {
            anchor = std::max(anchor, index[S[i]]);
            if (i == anchor) {
                ret.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ret;
    }
};