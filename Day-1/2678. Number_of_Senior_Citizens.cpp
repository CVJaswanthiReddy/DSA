2678. Number of Senior Citizens(Problem of the day)

#include <bits/stdc++.h>
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(const auto&str:details){
           
            string numberPart=str.substr(11,2);
            int age=stoi(numberPart);
            if(age >60){
                count++;
            }
        }
        return count;
    }
};