class Solution {
public:
    int solve(int i,vector<int>& nums, vector<int>&dp ){
        
        if(i>=nums.size())
                return 0;
        if(i==nums.size()-1)
                return nums[nums.size()-1];
        if(dp[i]!=-1)
                return dp[i];
        
        int take=nums[i]+ solve(i+2, nums,dp);
        int notTake=solve(i+1, nums,dp);
        
        return dp[i]= max(take,notTake);
        
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(nums.size(),-1);
        
        if(n==1)
                return nums[0];
        if(n==2)
                return max(nums[0],nums[1]);
        // return solve(0,nums,dp);
        dp[0]=nums[0];
        // dp[1]=nums[1];
        
        for(int i=1;i<n;i++){
            int take,notTake;
            if(i-2<0){
               take=nums[i];
            }else
                    take=nums[i]+dp[i-2];
            
            notTake=dp[i-1];
            
            dp[i]=max(take,notTake);
            
            
        }
        return dp[n-1];
    }
};