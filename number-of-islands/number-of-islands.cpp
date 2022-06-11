class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid){
        
        if(i>=grid.size() or j>=grid[0].size() or grid[i][j]!='1' )
                return;
        grid[i][j]='2';
        
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
     
        int rows=grid.size();
        if(rows==0)    
                return 0;
    
        int cols=grid[0].size();
        int noi=0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    noi+=1;
                    dfs(i,j,grid);
                }
            }
        }
        return noi;
    }
};