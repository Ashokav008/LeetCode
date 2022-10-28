class Solution {
public:
    int solve(int i, int n, vector<int>& nums, vector<int>& dp){
        if(i>n-1)
                return 0;
        if(i==n-1)
            return nums[n-1];
        if(dp[i]!=-1)
                return dp[i];
       int take=nums[i]+ solve(i+2,n,nums,dp);
        int notTake= solve(i+1,n,nums,dp);
        
        return dp[i]= max(take,notTake);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
                return nums[0];
        if(n==2)
                return max(nums[0],nums[1]);
        
        vector<int>dp1(n+1,-1),dp2(n+1,-1);
        
       int f=solve(0,n-1,nums,dp1) ;
        int s=solve(1,n,nums,dp2);
       return max(f,s); 
        
    }
};