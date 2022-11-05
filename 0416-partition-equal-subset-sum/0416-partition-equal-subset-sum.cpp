class Solution {
public:
    
    bool solve(int i , int sum, vector<int>& nums,vector<vector<int>>&dp){
        
        if(sum==0)
                return true;
        
        if(sum<0 or i<0)
            return false;
        if(dp[i][sum]!=-1)
                return dp[i][sum];
      
      bool  include=false, notInclude=false;
        
        if(nums[i]<=sum)
                include=solve(i-1, sum-nums[i],nums, dp ) or solve(i-1, sum,nums,dp);
        else{
            notInclude=solve(i-1, sum , nums, dp)  ;
        }
        
        
        return  dp[i][sum]= include or notInclude;
    }
    
    bool canPartition(vector<int>& nums) {
        
        
        int sum=0,n=nums.size();
        for(auto it: nums)
                sum+=it;
        if(sum%2==1)
                return false;
         sum/=2;
        vector<vector<int>>dp(n+1, vector<int>(sum+1,-1));
        return solve(n-1, sum , nums, dp);
        
    }
};