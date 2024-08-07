class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int score=0;
        
        for(int i=0;i<nums.size();i++){
            sort(nums[i].begin(), nums[i].end());
        }
        for(int j=0;j<nums[0].size();j++){
            int maxi=INT_MIN;
            for(int i=0;i<nums.size();i++){
                maxi=max(maxi,nums[i][j]);
            }
            score+=maxi;
        }
        return score;
    }
};