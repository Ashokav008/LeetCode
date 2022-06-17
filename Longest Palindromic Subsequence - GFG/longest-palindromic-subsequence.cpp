// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  int lps(string a,string b, int n,int m,vector<vector<int>>&dp){
      
      if(m==0 or n==0)
        return 0;
       if(dp[n][m]!=-1)
        return dp[n][m];
        
    if(a[n-1]==b[m-1])
        return dp[n][m]= 1+lps(a,b,n-1,m-1,dp);
     else
        return  dp[n][m]= max(lps(a,b,n-1,m,dp),lps(a,b,n,m-1,dp));
  }
  
    int longestPalinSubseq(string a) {
        //code here
        
        string b=a;
        reverse(a.begin(),a.end());
        int n=a.size(),m=n;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        lps(a,b,m,n,dp);
        
        return dp[n][m];
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends