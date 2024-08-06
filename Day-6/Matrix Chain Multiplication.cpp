//Matrix Chain Multiplication


//memoization
class Solution{
public:
    int f(int i,int j, int arr[],vector<vector<int>>& dp){
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int mini=1e+9;
        for(int k=i;k<j;k++){
            int steps= (arr[i-1]*arr[k]*arr[j])+f(i,k,arr,dp)+f(k+1,j,arr,dp);
            
            mini=min(mini,steps);
        }
        
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N, vector<int>(N,-1));
       return f(1,N-1,arr,dp);
    }
};


//tabulation
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N]={0};
        
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini=1e+9;
                 for(int k=i;k<j;k++){
                        int steps= (arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                        
                        mini=min(mini,steps);
                    }
                    dp[i][j]=mini;
            }
        }
       return dp[1][N-1];
    }
};