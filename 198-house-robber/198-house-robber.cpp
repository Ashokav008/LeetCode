class Solution {
public:
    
    int solve(int i, vector<int>& arr, vector<int>&dp){
        
        if(i<0)
                return 0;
        if(i==0)
                return arr[0];
        if(dp[i]!=-1)
                return dp[i];
        
        return  dp[i]= max(arr[i]+solve(i-2,arr, dp), solve(i-1, arr,dp) );
        
    }
    
    int rob(vector<int>& nums) {
        int ans=0;
        
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve( n-1, nums, dp);
        
        
    }
};