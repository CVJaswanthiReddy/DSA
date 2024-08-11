class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0;
        int j=0;
        for(int k=0;k<commands.size();k++){
            if(commands[k]=="DOWN"){
                if(i+1<n) i++;
                
            }
            else if(commands[k]=="RIGHT"){
                if(j+1<n) j++;
            }
            else if(commands[k]=="UP"){
                if(i-1 >= 0) i--;
            }
            else {
                if(j-1 >=0) j--;
            }
        }
        int ans=(i*n)+j;
        return ans;
    }
};