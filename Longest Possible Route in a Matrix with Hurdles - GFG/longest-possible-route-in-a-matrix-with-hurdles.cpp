// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:

int maxi=-1;
    
bool isSafe(int i,int j, vector<vector<int>> &matrix ,vector<vector<int>> &vis){
if(i<matrix.size() and j< matrix[0].size() and i>=0 and j>=0 and matrix[i][j]==1 and vis[i][j]==0){
        return true;
}
return false;
}
         
    
    void dfs(int i,int j, int x,int y,vector<vector<int>> &matrix ,vector<vector<int>> &vis,int cnt){
   
        // cout<<i<<" "<<j<<"  ";
        
        if(i==x and y==j)
       {
            maxi=max(maxi,cnt);
            return;
       }
    vis[i][j]=1; 
        if(isSafe(i-1,j,matrix,vis))
                 dfs(i-1,j,x,y,matrix,vis,cnt+1);
                 
          if(isSafe(i,j-1,matrix,vis))
                dfs(i,j-1,x,y,matrix,vis,cnt+1);
         if(isSafe(i+1,j,matrix,vis))
                 dfs(i+1,j,x,y,matrix,vis,cnt+1);
         if(isSafe(i,j+1,matrix,vis))
               dfs(i,j+1,x,y,matrix,vis,cnt+1);
               
    //   cout<<endl;
       vis[i][j]=0;
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        
        if(matrix[xs][ys]==0)
            return -1;
        
        int n=matrix.size();
         int m=matrix[0].size();
        vector<vector<int>>vis(n,vector<int>(m+1,0));
        int cnt=0;
         dfs(xs,ys,xd,yd,matrix,vis,cnt);
        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends