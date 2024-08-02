714. Best Time to Buy and Sell Stock with Transaction Fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int prevBuy, prevNotBuy, curBuy, curNotBuy;
        prevNotBuy=prevBuy=0;
        int profit=0;
        for(int index=n-1;index>=0;index--){
            //sell
             curNotBuy=max(+prices[index]-fee+prevBuy,
                              0+prevNotBuy);
            //buy 
            curBuy=max(-prices[index] + prevNotBuy,
                              0+prevBuy);
             
              prevBuy=curBuy;
              prevNotBuy=curNotBuy;
        }
        
        return prevBuy;         
    }
};