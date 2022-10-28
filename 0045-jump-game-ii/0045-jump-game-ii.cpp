class Solution {
public:
    
    int solve(int i, int n , vector<int>& nums,vector<int>& dp){
        
        if(i>=n-1)
                return 1;
        if(nums[i]==0)
                return 1e5;
        if(dp[i]!=-1)
                return dp[i];
        int reach=nums[i];
        int jumps=1e5;
        
        for(int j=i+1;j<=i+reach;j++){
           int thisPath=1+ solve(j,n,nums,dp);
            jumps=min(jumps,thisPath);
        }
        
        return dp[i]= jumps;
    }
    
    int jump(vector<int>& nums) {
        int i=0,n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(i,n,nums,dp)-1;
        
    }
};