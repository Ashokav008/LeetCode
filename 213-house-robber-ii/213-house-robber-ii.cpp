class Solution {
public:
    int solve(int l, int i, vector<int>&nums,vector<int>&dp){
        
        if(i<l)
                return 0;
        if(i==l)
                return nums[i];
        if(dp[i]!=-1)
                return dp[i];
        return dp[i]= max(nums[i]+ solve(l , i-2, nums, dp), solve(l , i-1, nums, dp));
        
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
       int i=0,j=n-1;
        vector<int>dp1(n,-1), dp2(n,-1);
        if(n==1)
                return nums[0];
        if(n==2)
                return max(nums[0],nums[1]);
        
      int ans1=solve(0,n-2,nums, dp1);
        
        int ans2=solve(1,n-1,nums, dp2);
                
        return max(ans1,ans2);
    }
};