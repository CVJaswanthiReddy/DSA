Make Two Arrays Equal by Reversing Subarrays

//problem of the day
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        int i=0,j=0;
        int n=target.size();
        int m=arr.size();
        while(i<n && j<m){
            if(target[i] != arr[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};