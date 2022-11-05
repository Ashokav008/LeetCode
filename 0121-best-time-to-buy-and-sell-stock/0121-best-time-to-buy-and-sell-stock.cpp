class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy=prices[0], maxProfit=0,profit=0;
        
        int n=prices.size();
        
        for(int i=1;i<n;i++){
            int profit=prices[i]-buy;
            maxProfit=max(maxProfit, profit);
            if(buy> prices[i])
                    buy=prices[i];
        }
        return maxProfit;
    }
};