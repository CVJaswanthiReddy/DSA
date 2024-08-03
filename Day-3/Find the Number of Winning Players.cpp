Find the Number of Winning Players
//contest
problem 1

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
    vector<unordered_map<int,int>>mp(n);
        for(const auto& p:pick){
            int player=p[0];
            int color=p[1];
            mp[player][color]++;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int required=(i+1);
            bool wins=false;
            for(const auto& j:mp[i]){
                if(j.second >= required){
                    wins=true;
                    break;
                }
            }
            if(wins){
                ans++;
            }
        }
       
        return ans;
    }
};