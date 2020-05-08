class Solution
{
public:
    // 暴力法 o(n*n) .i-j之间最小高度
    int largestRectangleArea1(vector<int> &heights)
    {
        int result = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int minHeight = INT_MAX;
            for (int j = i; j < heights.size(); j++)
            {
                minHeight = std::min(minHeight, heights[j]);
                result = std::max(result, minHeight * (j - i + 1));
            }
        }
        return result;
    }
    // 分治法: 找出最小高度, 要么在左边, 要么在右边, 要么左边+右边. 仍然超时
    int largestRectangleArea2(vector<int> &heights)
    {
        return division(heights, 0, heights.size() - 1);
    }

    int division(vector<int> &heights, int start, int end)
    {
        if (start > end)
        {
            return 0;
        }
        int minHeightPosition = start;
        for (int i = start + 1; i <= end; i++)
        {
            if (heights[i] < heights[minHeightPosition])
            {
                minHeightPosition = i;
            }
        }
        return std::max(std::max(division(heights, start, minHeightPosition - 1), division(heights, minHeightPosition + 1, end)), (end - start + 1) * heights[minHeightPosition]);
    }

    int largestRectangleArea(vector<int> &heights)
    {
        // 首部插入 哨兵 0
        heights.insert(heights.begin(), 0);
        // 尾部插入 哨兵 0
        heights.push_back(0);
        // 非递减栈, 栈内元素:从栈底->栈顶单调不减
        stack<int> notDescend;
        int maxResult = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!notDescend.empty() && heights[i] < heights[notDescend.top()])
            {
                int right = i;
                int current = notDescend.top();
                notDescend.pop();
                int left = notDescend.top();
                // 取left和right之间的矩形, 故需要+1, -1. 计数之后再+1
                maxResult = std::max(maxResult, heights[current] * ((right - 1) - (left + 1) + 1));
            }
            notDescend.push(i);
        }
        return maxResult;
    }
};