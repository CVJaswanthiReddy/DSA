Longest Continuous Increasing Subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=0;
         int maxLength = 1; 
        int currentLength = 1; 
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                currentLength++;
            }
            else{
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
         maxLength = max(maxLength, currentLength);

        return maxLength;
    }
};