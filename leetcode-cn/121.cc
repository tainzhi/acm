class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minIn = INT_MAX, profit = 0;
        for (int pr: prices){
            minIn = std::min(minIn, pr);
            profit = std::max(profit, pr - minIn);
        }
        return profit;
    }
};