//Number of Longest Increasing Subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        int maxi=1;
        vector<int>dp(n,1),count(n,1);
        
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i] > arr[prev] && 1+dp[prev] > dp[i]){
                    dp[i]=1+dp[prev];
                    //if same means
                    count[i]=count[prev];
                } 
                else if(arr[prev] < arr[i] && 1+dp[prev] == dp[i]){
                    //same come means we will add
                    count[i]+=count[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi) ans+=count[i];
        }
        return ans;
    }
};