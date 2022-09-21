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
    
    int rob(vector<int>& arr) {
        int ans=0;
        
        int n=arr.size();
        vector<int>dp(n,0);
        dp[0]=arr[0];
        
        if(n==1)
                return arr[0];
        if(n==2)
                return max(arr[0], arr[1]);
        
        for(int i=1;i<n;i++){
            
            int l;
            if(i-2<0)
             l=arr[i];
            else{
                l=arr[i]+ dp[i-2];
            }
           int r=dp[i-1];
            
            dp[i]=max(l,r);
            
        }
        
        return max(dp[n-1], dp[n-2]);
        // return solve( n-1, arr, dp);
        
        
    }
};