class Solution {
public:
    
 
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n+1];
        // dp[0]=cost[0];
        int f=cost[0];
        int s=cost[1];
        // dp[1]=cost[1];
        int curr;
        for(int i=2;i<n;i++){
           // dp[i]=cost[i] + min( dp[i-1],dp[i-2]); 
           curr=cost[i] + min(f,s);
            f=s;
            s=curr;
            
        }
        return min(f,s);
    }
};