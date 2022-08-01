class Solution {
public:
    
    int ans=0;
    
    void dfs(int i,int j, int n,int m , vector<vector<int>>&vis){
           
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j]==1)
                return;
        
            
        if(i==n-1 and j==m-1){
            ans++;
            return;
        }
        // cout<<i<<" "<<j<<endl;
        
        vis[i][j]=1;
        dfs(i+1,j,n,m,vis);
        dfs(i,j+1,n,m,vis);
        vis[i][j]=0;
        
    }
    
    int uniquePaths(int n, int m) {
        ans=0;
        vector<vector<int>>vis(n+1,vector<int>(m+1,1));
        int i=0,j=0;
     // dfs(i,j,n,m,vis);
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                vis[i][j]=vis[i-1][j]+vis[i][j-1];
            }
        }
        return vis[n-1][m-1];
        
        
    }
};