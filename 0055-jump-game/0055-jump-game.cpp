class Solution {
public:
    
    bool solve(int i, int n , vector<int>& nums,vector<int>& dp){
        
        if(i>=n-1)
                return true;
        if(dp[i]!=-1)
                return dp[i];
        
        int reach=nums[i];
        
        for(int j=i+1;j<=i+reach;j++){
               if( solve(j,n,nums,dp))
                    return dp[i]= 1;
        }
        return dp[i]= 0;
    }
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};