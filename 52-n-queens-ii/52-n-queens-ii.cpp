class Solution {
public:
    int ans=0;
    
    bool isPossible(int i,int j,int n,vector<vector<int>>&board){
        int x=i,y=j;
        while(y>=0){
            if(board[x][y]==1)
                    return false;
            y--;
        }
    
        x=i,y=j;
        while(x>=0 and y>=0){
            if(board[x][y]==1)
                    return false;
            x--;
            y--;
        }
        x=i,y=j;
        while(x<n and y>=0){
                if(board[x][y]==1)
                    return false;
            x++,y--;
        }
        return true;
    }
    
    void solve(int col,int n,vector<vector<int>>&board){
        if(col==n){
            ans+=1;
            return;
        }
        
    for(int i=0;i<n;i++){
        
        if(isPossible(i,col,n,board)){
            board[i][col]=1;
            solve(col+1,n,board);
            board[i][col]=0;
        }
    }
    
    }
    
    int totalNQueens(int n) {
      ans=0;
        vector<vector<int>>board(n,vector<int>(n,0));
        solve(0,n,board);
        
        return ans;
        
    }
};