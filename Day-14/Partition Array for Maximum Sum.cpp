//memoization
class Solution {
public:
    int f(int index,vector<int>& arr,int k,vector<int>& dp ){
        int n=arr.size();
        if(index==n){
            return 0;
        }
        if(dp[index] != -1) return dp[index];
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        for(int j=index;j<min(index+k,n);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+f(j+1,arr,k,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[index]= maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(0,arr,k,dp);
    }
};

//tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        
        for(int index=n-1;index>=0;index--){
             int len=0;
            int maxi=INT_MIN;
            int maxAns=INT_MIN;
            for(int j=index;j<min(index+k,n);j++){
                len++;
                maxi=max(maxi,arr[j]);
                int sum=len*maxi+dp[j+1];
                maxAns=max(maxAns,sum);
            }
            dp[index]= maxAns;
            }
        return dp[0];
    }
};