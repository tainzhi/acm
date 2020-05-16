class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        bool visit[nums.size()];
        std::fill_n(visit, nums.size(), false);
        int maxLength = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visit[i])
            {
                int next = nums[i];
                int lenCount = 1;
                visit[i] = true;
                while (next != i)
                {
                    lenCount++;
                    visit[next] = true;
                    next = nums[next];
                }
                maxLength = std::max(maxLength, lenCount);
            }
        }
        return maxLength;
    }
};