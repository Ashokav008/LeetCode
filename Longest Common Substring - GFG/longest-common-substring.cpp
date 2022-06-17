// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int maxi=INT_MIN;
    
    int lcs(string s1 , string s2, int n,int m,vector<vector<int>>&dp){
        if(n==0 or m==0)
            return 0;
            
        if(dp[n][m]!=0)
        return dp[n][m];
        
        if(s1[n-1] == s2[m-1]){
            
        // cout<<1<<endl;
            
          dp[n][m] = 1+lcs(s1,s2,n-1,m-1,dp);
          maxi=max(dp[n][m],maxi);
          return dp[n][m];
        }
        else{
             dp[n][m]= 0;
            (lcs(s1,s2,n-1,m,dp),lcs(s1,s2,n,m-1,dp));
             return 0;
          }
    }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {   
        // your code here
        //ha lcs cha variatoin aahe
         maxi=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        //  lcs(s1,s2,n,m,dp);
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                
                if(i==0 or j==0)
                    dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxi=max(maxi,dp[i][j]);
                }
                else
                    dp[i][j]=0;
                }
        }
        
        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends