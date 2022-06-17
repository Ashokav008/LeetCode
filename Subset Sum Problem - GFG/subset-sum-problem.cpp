// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool flg=false;
int rec(vector<int>&arr,int sum, int n ,vector<vector<int>>&dp){
      if(sum==0)
        return 1;    
    
    if(n==0)
        return 0;
    
    if(dp[n][sum]!=-1)
        return dp[n][sum];
        
    if(arr[n-1]<=sum)
        return dp[n][sum]=rec(arr,sum-arr[n-1],n-1,dp) || rec(arr,sum,n-1,dp);
    
    else
        return dp[n][sum]= rec(arr,sum,n-1,dp);
}

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        // int dp[n+1][sum+1];
        // memset(dp,0,sizeof(dp));
        // flg=false;
        // cout<<"Calling"<<endl;
      return rec(arr,sum,n,dp);
        // return flg;
//         for(int i=0;i<n+1;i++){
//             for(int j=0;j<sum+1;j++){
       
//                 if(i==0)
//                     dp[i][j]=0;
//                  if(j==0)
//                   dp[i][j]=1;
//                 //   else if(dp[i][j]!=-1)
                
//             }
            
//         }
//          for(int i=1;i<n+1;i++){
//             for(int j=1;j<sum+1;j++){
                
                    
//                  if(arr[i-1]<=j){
//                       dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];
//                   }
//                   else{
//                       dp[i][j]=dp[i-1][j];
//                   }
// }
// }
//         return dp[n][sum];
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
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends