class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>>vis(m+1,vector<int>(n+1,1)) ;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                vis[i][j]=vis[i-1][j]+vis[i][j-1];
            }
        }
        return vis[m-1][n-1];
    }
};