class Solution {
public:
    vector<vector<string>>ans;
    int isSafe(int i,int j,vector<vector<int>>&board,int n){
    
        
          int x=i,y=j;
     
        while(y>=0)
        {
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
            x++;
            y--;
        }
        // cout<<"below  "<<endl;
        return true;
    }
    
    void solve(int col, vector<vector<int>>&board,int n){
        if(col==n){
            vector<string>ans1;
            for(int i=0;i<n;i++){
                string str;
                for(int j=0;j<n;j++){
                    if(board[i][j]==0)
                            str+='.';
                    else
                        str+='Q';
                }
            ans1.push_back(str);
            }
            cout<<"one vector pushed!!!"<<endl;
            
            ans.push_back(ans1);
            return;
        }

        for(int i=0;i<n;i++){
            
            if(isSafe(i,col,board,n)){
                
                board[i][col]=1;
                solve(col+1,board,n);
                board[i][col]=0;
            }
            
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<int>>board(n,vector<int>(n,0));
        int col=0;
        solve(col,board,n);
        return ans;
        
    }
};