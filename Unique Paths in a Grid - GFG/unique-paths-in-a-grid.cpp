//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod=1e9+7;
    int uniquePaths(int n, int m, vector<vector<int>> &arr) {
        if(arr[0][0]==0 or arr[n-1][m-1]==0)
            return 0;
       for(int i=1;i<m;i++){
           if(arr[0][i]!=0)
                 arr[0][i]=arr[0][i-1]%mod;
       }
       for(int i=1;i<n;i++){
           if(arr[i][0]!=0)
                arr[i][0]=arr[i-1][0] %mod;
       }
       
       for(int i=1;i<n;i++){
           for(int j=1;j<m;j++){
               if(arr[i][j]!=0)
               arr[i][j]=((arr[i-1][j])%mod + (arr[i][j-1])%mod)%mod;
           }
       }
       return arr[n-1][m-1]%mod;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends