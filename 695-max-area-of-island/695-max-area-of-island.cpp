class Solution {
public:
    
    int ans=0;
    
  
    void dfs(int i,int j,int &d,vector<vector<int>>& grid )
    {
        
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
                return ;
        
            d=d+1;
        
            ans=max(ans,d);
            grid[i][j]=0;
        
            dfs(i+1,j,d,grid);
            dfs(i,j+1,d,grid);
            dfs(i-1,j,d,grid);
            dfs(i,j-1,d,grid);
        
        
    
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        int maxi=INT_MIN;
        int d=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    d=0;
                    dfs(i,j,d,grid);
                }
                
            }
            
        }
        
      return ans;  
    }
};