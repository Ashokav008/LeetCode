class Solution {
public:
    int lcs(string s1,string s2, int i,int j,vector<vector<int>>&dp){
        
        if(i<0 or j<0)
            return 0;
        
        if(dp[i][j]!=0)
                return dp[i][j];
        
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]= 1+ lcs(s1,s2,i-1,j-1,dp);
        }
        else
                return dp[i][j]= max(lcs(s1,s2,i-1,j,dp), lcs(s1,s2,i,j-1,dp));
        
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
       
        int n1=text1.size(),n2=text2.size();
       vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        int i=0,j=0;
        // return lcs(text1,text2,n1,n2,dp);
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            
        }
        
        return dp[n1][n2];
    }
};