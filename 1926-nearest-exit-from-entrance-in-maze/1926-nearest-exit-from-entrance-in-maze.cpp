class Solution {
public:
    
    bool isValid(int i,int j,int n,int m){
        if(i<0 or j<0 or i>=n or j>=m)
            return false;
        
        return true;
    }
    
    bool isDoor(int i,int j,int n,int m){
        
        if(i==0 or j==0 or i==n-1 or j==m-1)
            return true;
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    
        
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>>q;
        vector<pair<int,int>>drs;
        drs.push_back({1,0});
        drs.push_back({0,1});
        drs.push_back({-1,0});
        drs.push_back({0,-1});

        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int level=0;
        
        while(!q.empty()){
            int sz=q.size();
            level++;
            while(sz--){
                
              auto front=q.front();
                q.pop();
                
                int i=front.first;
                int j=front.second;
                maze[i][j]='+';
                
                
                    
                
                    
                    if(isValid(i+1,j,n,m) and maze[i+1][j]=='.'){
                        if(isDoor(i+1,j,n,m))
                            return level;
                        
                        maze[i+1][j]='+';
                        q.push({i+1,j});   
                    }
                 if(isValid(i,j+1,n,m) and maze[i][j+1]=='.'){
                        if(isDoor(i,j+1,n,m))
                            return level;
                        
                        maze[i][j+1]='+';
                        q.push({i,j+1});   
                    }
                 if(isValid(i-1,j,n,m) and maze[i-1][j]=='.'){
                        if(isDoor(i-1,j,n,m))
                            return level;
                        
                        maze[i-1][j]='+';
                        q.push({i-1,j});   
                    }
                 if(isValid(i,j-1,n,m) and maze[i][j-1]=='.'){
                        if(isDoor(i,j-1,n,m))
                            return level;
                        
                        maze[i][j-1]='+';
                        q.push({i,j-1});   
                    }
                
            }
          
            
        }
        return -1;
    }
};