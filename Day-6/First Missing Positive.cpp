//First Missing Positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missingNumber=1;
        sort(nums.begin(),nums.end());
       for(int number:nums){
           if(number > 0){
               if(number == missingNumber){
                   missingNumber++;
               }
               else if(number > missingNumber){
                   break;
               }
           }
       }
        return missingNumber;
    }
};