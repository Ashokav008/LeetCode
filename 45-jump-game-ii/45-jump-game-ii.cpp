class Solution {
public:
    // int ans=1;
    int solve(int i, int n,vector<int>& arr, vector<int>&dp){
      
        if(i>=n-1)
                return 1;
        if(arr[i]==0)
                return 1e5;
        if(dp[i]!=-1)
            return dp[i];
        int reach=arr[i];
        int ans=INT_MAX;
        
        for(int curr=i+1;curr<=i+ reach;curr++){
            
            int thisPath =  1 + solve(curr, n, arr, dp);
            ans=min(ans,thisPath);
        }
        
      return  dp[i]=  ans;
    }
    
    int jump(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
      return solve(0, n, arr, dp)-1;
        
//         
       
        
    }
};