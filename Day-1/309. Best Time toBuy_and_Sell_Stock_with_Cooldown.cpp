309. Best Time to Buy and Sell Stock with Cooldown

class Solution {
public:
    int f(int index, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }
        if (dp[index][buy] != -1) return dp[index][buy];
        
        int profit;
        if (buy) {
            profit = max(-prices[index] + f(index + 1, 0, prices, dp),
                         f(index + 1, 1, prices, dp));
        } else {
            profit = max(prices[index] + f(index + 2, 1, prices, dp),
                         f(index + 1, 0, prices, dp));
        }
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // dp[index][buy]
        return f(0, 1, prices, dp);
    }
};
