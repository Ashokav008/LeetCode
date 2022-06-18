// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    
    bool isSafe(int i,int j,int n,vector<vector<int>> &mat,vector<vector<int>> &vis){
        if(i<0 or j<0 or i>=n or j>=n or vis[i][j]==1 or mat[i][j]==0)
            return false;
        
        return true;
    }
    
    void dfs(int i,int j,int n,vector<vector<int>> &mat,string &path,vector<vector<int>>&vis){
        
        
            if(i==n-1 and j==n-1)
                {   
                // cout<<path<<endl;
                    ans.push_back(path);
                    path.pop_back();
                    return ;
                }
        vis[i][j]=1;
        
        if(isSafe(i+1,j,n,mat,vis))
            dfs(i+1,j,n,mat,path+="D",vis);
            
         if(isSafe(i,j-1,n,mat,vis))
            dfs(i,j-1,n,mat,path+="L",vis);
            
          if(isSafe(i-1,j,n,mat,vis))
            dfs(i-1,j,n,mat,path+="U",vis);
            
          if(isSafe(i,j+1,n,mat,vis))
            dfs(i,j+1,n,mat,path+="R",vis);
            
            vis[i][j]=0;
            path.pop_back();
    }
    
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        // Your code goes here
        ans.clear();
        if(mat[0][0]==0 or mat[n-1][n-1]==0)
            return ans;
            
        int i=0,j=0;
        string path="";
        vector<vector<int>>vis(n,vector<int>(n,0));
        
         dfs(i,j,n,mat,path,vis);
        
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends