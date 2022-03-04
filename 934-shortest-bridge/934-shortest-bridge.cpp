class Solution {
public:
    
    void floodFill(int i,int j,int n,int m,vector<pair<int,int>>&v,vector<vector<int>>&grid){
        
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0)
              return;
        
        grid[i][j]=0;
        
        v.push_back({i,j});
        
        floodFill(i+1,j,n,m,v,grid);
        floodFill(i,j+1,n,m,v,grid);
        floodFill(i-1,j,n,m,v,grid);
        floodFill(i,j-1,n,m,v,grid);
        
        return;
        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        vector<pair<int,int>>v1,v2;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){                
                if(v1.size()==0){
                    floodFill(i,j,n,m,v1,grid);
                }
                else{
                    floodFill(i,j,n,m,v2,grid);
                 }
                    
              }
            }
            
        }
        
        int mini=INT_MAX;
        for(auto i:v1){
            
            for(auto j:v2){
                
                mini=min(mini,(abs(i.first-j.first)+abs(i.second-j.second))-1);
            }
        }
        
        return mini;
        
    }
};