class Solution {
public:
    int lcs(string word1,string word2,int m,int n, vector<vector<int>>&dp){
        
        if(m==0 or n==0)
            return 0;
        
        if(word1[m-1]==word2[n-1])
               return dp[m][n] = 1+lcs(word1,word2,m-1,n-1,dp);
        
        if(dp[m][n]!=-1)
                return dp[m][n];
        
        
        return dp[m][n]=max(lcs(word1,word2,m-1,n,dp),lcs(word1,word2,m,n-1,dp));
            
    }
    
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                
                if(i==0 or j==0)
                    dp[i][j]=0;
                
                else if(word1[i-1]==word2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        // lcs(word1,word2,m,n,dp);
        int l=dp[m][n];
        cout<<l<<endl;
        return m+n-2*l;
        
        
    }
};