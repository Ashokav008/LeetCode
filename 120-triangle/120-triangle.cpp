class Solution {
public:
    int solve(int i,int j,int n,	vector<vector<int>>&dp,vector<vector<int>>& t){
        
        if(i==n-1)
            return t[i][j];
        if(dp[i][j]!=-1){
           return dp[i][j];
        }
        
        int bottom_left=t[i][j]+solve(i+1,j,n,dp,t);
        int bottom_right=t[i][j]+solve(i+1,j+1,n,dp,t);
        
        return dp[i][j]=min(bottom_left,bottom_right);
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        
        int n=t.size();
       	vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0,0,n,dp,t);
        
    }
};