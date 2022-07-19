class Solution {
public:
    bool solve(int i,int n, vector<int>& nums,vector<int>&dp){
        if(i>=n-1)
                return true;
        if(dp[i]!=-1)
                return dp[i];
        int reach=i+nums[i];
        for(int k=i+1;k<=reach;k++){
            if(solve(k,n,nums,dp))
                    return dp[i]=true;
        }
        
        return dp[i]=false;
    }
    
    bool canJump(vector<int>& nums) {
        int i=0,n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(i,n,nums,dp);
    }
};