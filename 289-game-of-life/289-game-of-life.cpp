class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>> &board){
        
        int n=board.size(),m=board[0].size();
        
        if( i<0 or j<0 or i>=n or j>=m or board[i][j]==0 )
                return false;
        
        return true;
    }
    
    int totalN(int i,int j,vector<vector<int>>& board){
        int lnbrs=0;
        
        if(  isValid(i+1,j,board) and board[i+1][j]==1 )
                lnbrs++;
        
           if(isValid(i,j+1,board) and   board[i][j+1]==1 )
                lnbrs++;
           if(isValid(i-1,j,board) and   board[i-1][j]==1 )
                lnbrs++;
           if( isValid(i,j-1,board) and board[i][j-1]==1 )
                lnbrs++;
           if( isValid(i+1,j-1,board) and board[i+1][j-1]==1 )
                lnbrs++;
           if( isValid(i+1,j+1,board)  and  board[i+1][j+1]==1 )
                lnbrs++;
           if(isValid(i-1,j+1,board) and  board[i-1][j+1]==1 )
                lnbrs++;
           if(isValid(i-1,j-1,board) and   board[i-1][j-1]==1 )
                lnbrs++;
        
        return lnbrs;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size(),m=board[0].size();
        vector<vector<int>> ans( n , vector<int> (m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               int nbrs=totalN(i,j,board);
                cout<<nbrs<<" ";
                if(board[i][j]==1){
                if(nbrs<2)
                        ans[i][j]=0;
                else if(nbrs==2 or nbrs==3)
                    ans[i][j]=1;
                    
                else if(nbrs>3)
                        ans[i][j]=0;
                
            }
                else{
                    if(nbrs==3)
                            ans[i][j]=1;
                }
            }
            cout<<endl;
        }
        board.clear();
        board=ans;
        return;
    }
};