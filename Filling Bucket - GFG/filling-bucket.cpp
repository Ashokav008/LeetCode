//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e8;

    int solve(int n,vector<int>&dp){
      if(n==0)
        return 1;
      if(n<0)
        return 0;
      if(dp[n]!=-1)
        return dp[n];
       long long  one=fillingBucket(n-1)%mod;
       long long  two=fillingBucket(n-2)%mod;
      
      return dp[n]= (int)(one+two)%mod ;
        
    }
    int fillingBucket(int n) {
    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        
        dp[i]=(dp[i-1] +dp[i-2])%mod;
    }
    
       return (int)dp[n]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends