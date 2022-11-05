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
        vector<vector<bool>>dp(n+1, vector<bool>(sum+1,-1));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=sum;i++){
            dp[0][i]=0;
        }
        
        
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=sum;j++){
                bool  include=false, notInclude=false;
               if(nums[i-1]<=j)
                   include=dp[i-1][j-nums[i-1]] or dp[i-1][j]; 
                
             else
                notInclude=dp[i-1] [j];
                
            dp[i][j]= include or notInclude;
            }
        }
        
        return dp[n][sum];
        
    }
};