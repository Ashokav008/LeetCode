class Solution {
public:
    
    int ans=0;
    
    
    void dfs(int i,int j,int m,int n, int &area,vector<vector<int>>&grid){
        
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0)
            return;
   
         
        grid[i][j]=0;
        cout<<i<<" "<<j<<"\n";
        area=area+1;
        ans=max(ans,area);
       
        dfs(i+1,j,m,n,area,grid);
        dfs(i,j+1,m,n,area,grid);
        dfs(i-1,j,m,n,area,grid);
        dfs(i,j-1,m,n,area,grid);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        int n=grid.size();
        int m=grid[0].size();
        int area;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    area=0;
                    dfs(i,j,m,n,area,grid);
                    
                }
            }
        }
        return ans;
    }
};