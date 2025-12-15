class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        const int n = prices.size();

        int min = INT_MAX;
        for (int i = 0; i < n; i++) {

            if (prices[i] < min)
                min = prices[i];
            else
                profit = std::max(profit, prices[i] - min);
        }

        return profit;
    }
};