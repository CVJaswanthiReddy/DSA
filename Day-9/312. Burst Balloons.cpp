312. Burst Balloons


//memoization
class Solution {
public:
    int f(int i,int j, vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        int maxi=INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        for(int index=i;index<=j;index++){
            int cost=nums[i-1]*nums[index]*nums[j+1]+f(i,index-1, nums,dp)+f(index+1,j,nums,dp);
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n-2,nums,dp);
    }
};

//tabulation
class Solution {
public:

    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                int maxi=INT_MIN;
                 for(int index=i;index<=j;index++){
                    int cost=nums[i-1]*nums[index]*nums[j+1]+dp[i][index-1]+dp[index+1][j];
                    maxi=max(maxi,cost);
                }
                 dp[i][j]=maxi;
            }
        }
        return dp[1][n-2];
    }
};