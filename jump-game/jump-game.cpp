class Solution {
public:
   int step=0;
     bool solve(int i,int n , vector<int>&nums,vector<int>&dp){
           if(i>=n-1){
                return true;
           }
         int reachable=i+nums[i];
         if(dp[i]!=-1)
                return dp[i];
        for(int k=i+1;k<=reachable;k++){
            
        if(  solve(k,n,nums,dp))
                return dp[i]= true;
            
        }
            
      return  dp[i]=false;   
         
       } 
    
    bool canJump(vector<int>& nums) {
     
      int n=nums.size();
        // int jump=nums[0];
        vector<int>dp(n+1,-1);
        return solve(0,n,nums,dp);
        
    }
};