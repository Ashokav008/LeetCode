class Solution {
public:
    
    bool ok=true;
    int moves=0;
    
    void dfs(int i,int j,int n,int m,int &ans,vector<vector<int>>&grid){
        
          if (i<0 or j<0 or i>=n or j>=m or grid[i][j]==0)
            return;
        
          else  if((i==0 or j==0 or i==n-1 or j==m-1)){
            ok=false;
            return;
        }
    
        grid[i][j]=0;
        ans=ans+1;  
        
          dfs(i+1,j,n,m,ans,grid);
          dfs(i,j+1,n,m,ans,grid);
          dfs(i-1,j,n,m,ans,grid);
          dfs(i,j-1,n,m,ans,grid);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) { 
        moves=0;
        int n=grid.size();
        int m=grid[0].size();
      int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    ans=0;
                    dfs(i,j,n,m,ans,grid);
                    if(ok)
                        moves+=ans;
                    
                    ok=true;
                    ans=0;
                    }
                }
            }
        
        
        
        return moves;
    }
};