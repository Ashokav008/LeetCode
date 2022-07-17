class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int buy=prices[0],n=prices.size();
        int profit=0;
        int maxProfit=0;
        
        for(int i=0;i<n;i++){
            profit=prices[i]-buy;
            maxProfit=max(profit,maxProfit);
            if(buy>prices[i])
                    buy=prices[i];
        }
        
        return  maxProfit;
    }
};