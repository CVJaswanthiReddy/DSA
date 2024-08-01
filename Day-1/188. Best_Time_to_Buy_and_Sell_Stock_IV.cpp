188. Best Time to Buy and Sell Stock IV

class Solution {
public:
    int f(int index,int buy,int k,vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(index == prices.size() || k==0){
            return 0;
        }
        
        int profit=0;
        if(dp[index][buy][k] != -1) return dp[index][buy][k];
        if(buy){
            profit=max(-prices[index]+f(index+1,0,k,prices,dp), 0+f(index+1,1,k,prices,dp));
        }else{
            profit= max(prices[index]+f(index+1,1,k-1,prices,dp), 0+f(index+1,0,k,prices,dp));
        }
        dp[index][buy][k]=profit;
        return dp[index][buy][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
         vector<vector<vector<int>>> dp(n, 
                                       vector<vector<int>>(2, (vector<int>(k+1,-1))));
        return f(0,1,k,prices,dp);
    }
};