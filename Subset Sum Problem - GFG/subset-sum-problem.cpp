// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
int dp[101][10001];

   
 bool solve(int arr[],int n,int sum){
     
    if(sum==0)
        return 1;
    if(n==0 or sum<0)
        return 0;
    
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    
    if(arr[n-1]<=sum){
         dp[n][sum] = solve(arr,n-1,sum) or solve(arr,n-1,sum-arr[n-1]);
    }
    else
         dp[n][sum] = solve(arr,n-1,sum);
        
        
     return dp[n][sum];
 }

    bool isSubsetSum(int n, int arr[], int sum){
          
            dp[n+1][sum+1];
            memset(dp,-1,sizeof(dp));
         return  solve(arr,n,sum);
            
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends