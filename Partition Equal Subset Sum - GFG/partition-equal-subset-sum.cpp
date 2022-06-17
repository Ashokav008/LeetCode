// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int arr[],int sum,int n , vector<vector<int>>&dp){
        if(n==0)
            return 0;
        if(sum==0)
            return 1;
        
        if(arr[n-1]<=sum)
            return solve(arr,sum-arr[n-1],n-1,dp) or solve(arr,sum,n-1,dp);
        else
            return solve(arr,sum,n-1,dp);
    }

    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2==1)
            return 0;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        return solve(arr,sum/2,n,dp);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends