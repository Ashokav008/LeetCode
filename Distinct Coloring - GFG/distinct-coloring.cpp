//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
// long long int dp[100000][3];
    long long int  solve(int i, int n, int pColor,int r[], int g[], int b[],vector<vector<long long int>>&dp){
        
        if(i==n)
            return 0;
        if(dp[i][pColor]!=-1)
            return dp[i][pColor];
       long long int f=0; 
        if(pColor==0){
            f=r[i] + min( solve(i+1, n, 1,r,g,b,dp) , solve(i+1, n, 2,r,g,b,dp));
            
        }else if(pColor==1){
             f=g[i] + min( solve(i+1, n, 0,r,g,b,dp) , solve(i+1, n, 2,r,g,b,dp));
        }
        else if(pColor==2){
             f=b[i] + min( solve(i+1, n, 0,r,g,b,dp) , solve(i+1, n, 1,r,g,b,dp));
            
        }
        // cout<<f<<s<<t<<endl;
        return dp[i][pColor]= f;
        
    }
    

    long long int distinctColoring(int n, int r[], int g[], int b[]){
        vector<vector<long long int>>dp(n+1,vector<long long int>(3,-1));
        // memset(dp,-1,sizeof(dp));
         long long int  f=0,s=0,t=0;
        f=solve(0,n,0,r,g,b,dp);
        s=solve(0,n,1,r,g,b,dp);
        t=solve(0,n,2,r,g,b,dp);
        // cout<<f<<s<<t<<endl;
        return min(f,min(s,t));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends