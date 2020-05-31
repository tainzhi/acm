class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, inPrice = -1;
        for (int pr: prices) {
            if (inPrice == -1) {
                inPrice = pr;
            } else {
                if (pr < inPrice) {
                    inPrice = pr;
                } else {
                    profit += pr - inPrice;
                    inPrice = pr;
                }
            }
        }
        return profit;
    }
};