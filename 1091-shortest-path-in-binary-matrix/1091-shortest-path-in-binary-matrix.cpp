class Solution {
public:
     
    vector<pair<int,int>>drs={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 or grid[n-1][n-1]==1)
            return   -1;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int level=0;
        while(!q.empty()){
            
            int sz=q.size();
            while(sz--){
                
                pair<int,int> p=q.front();
                q.pop();
              
               if(p.first==n-1 and p.second==n-1)
                    return level+1;
                
                for(auto &i:drs){
                    int x=i.first+p.first;
                    int y=i.second+p.second;
             
                if(x<0 or y<0 or x>=n or y>=n or grid[x][y]==1 )
                        continue;
                    
                grid[x][y]=1;
                q.push({x,y});
                    
                }
            }
            level++;
            
        }
        
        return -1;
    }
};