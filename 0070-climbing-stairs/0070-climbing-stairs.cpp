class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
                return 1;
        // vector<int>dp(n,0);
        // dp[0]=1;
        int f=1;
        int s=2;
        // dp[1]=2;
        for(int i=2;i<n;i++){
            int curr=f+s;
            f=s;
            s=curr;
            // dp[i]=dp[i-1]+ dp[i-2];
        }
        return s;
        
    }
};