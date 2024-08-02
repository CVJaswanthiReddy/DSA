Longest Increasing Subsequence

class Solution {
public:
   int lengthOfLIS(const vector<int>& nums) {
        int n = nums.size();
       if(n==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        
        for(int index=n-1;index>=0;--index){
            for(int prev=-1;prev<index;++prev){
                 int len = dp[index + 1][prev+1];
                    if (prev == -1 || nums[index] > nums[prev]) {
                    len = max(len, 1 + dp[index + 1][index+1]);
                }
                 dp[index][prev + 1] = len;
            }
        }
        return dp[0][0];
    }
};
