class Solution {
public:
    
    
    int moves=0;
    void dfs(int i,int j,int n,int m,vector<vector<int>>&grid){
        
     if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0)
            return;
        
        grid[i][j]=0;
        moves=moves+1;  
        
         dfs(i+1,j,n,m,grid);
          dfs(i,j+1,n,m,grid);
          dfs(i-1,j,n,m,grid);
          dfs(i,j-1,n,m,grid);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) { 
        moves=0;
        int n=grid.size();
        int m=grid[0].size();
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                if(grid[i][j]==1){
                   dfs(i,j,n,m,grid);   
                }
                }
            }
        }
        
        moves=0;
        //finding all middle iselands
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   dfs(i,j,n,m,grid);
                       
                }
            }
        }
        return moves;
    }
};