class Solution {
public:
    
   int recursive(int i,vector<int>& cost){
       
       if(i<0)
            return 0;
       
      if(i==0)
            return cost[0];
       if(i==1)
            return cost[1];
       
       return cost[i] + min(recursive(i-1, cost),recursive(i-2, cost));
       
   }
    
    int minCostClimbingStairs(vector<int>& cost) {
       
       // return min( recursive(cost.size()-1, cost),recursive(cost.size()-2, cost));
        int n=cost.size();
        int dp[n+1];
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
           dp[i]=cost[i] + min( dp[i-1],dp[i-2]); 
        }
        
        return min(dp[n-1],dp[n-2]);
    }
};