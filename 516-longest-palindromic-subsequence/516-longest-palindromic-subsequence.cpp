class Solution {
public:
    
    int lcs(string s1 ,string s2,int x,int y, vector<vector<int>>&dp){
        if(x==0 or y==0)
                return 0;
        
        if(dp[x][y]!=-1)
                return dp[x][y];
        
        if(s1[x-1]==s2[y-1])
            return dp[x][y]=1+lcs(s1,s2,x-1,y-1,dp);
        
        else
        {
            return dp[x][y] = max(lcs(s1,s2,x-1,y,dp),lcs(s1,s2,x,y-1,dp));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        string sr=s;
        reverse(s.begin(),s.end());
        int m=s.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        // cout<<s<<"   "<<sr<<endl;
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 or j==0)
                    dp[i][j]=0;
            }
        }
           for(int i=1;i<m+1;i++){
            for(int j=1;j<m+1;j++){
             
                if(s[i-1]==sr[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                
                else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m][m];
        // return lcs(s,sr,m,m,dp);
        
    }
};