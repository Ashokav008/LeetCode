class Solution {
public:
    
    bool flg=false;
    
    bool isSafe(int i,int j ,int pos,vector<vector<char>>& board,  vector<vector<bool>>&vis, string word){
        
        int m=board.size(),n=board[0].size();
        
        if(i>=m or j>=n or i<0 or j<0 or board[i][j]!=word[pos] or vis[i][j]==1)
                return false;
        
        return true;
                
        
    }
    
    void dfs(int i,int j , int pos,vector<vector<char>>& board,  vector<vector<bool>>&vis, string word){
        
     // cout<<i<<" "<<j<<endl;
        if(pos==word.size()-1){
            flg=true;
            return;
        }
        vis[i][j]=1;
        // if(word[pos]!=board[i][j]){
        //     return ;
        // }
       
            
            if(isSafe(i+1,j,pos+1,board,vis,word))
                dfs(i+1,j,pos+1,board,vis,word);
        
            if(isSafe(i,j+1,pos+1,board,vis,word))
                dfs(i,j+1,pos+1,board,vis,word);
            
            if(isSafe(i-1,j,pos+1,board,vis,word))
                dfs(i-1,j,pos+1,board,vis,word);
            
            if(isSafe(i,j-1,pos+1,board,vis,word))
                dfs(i,j-1,pos+1,board,vis,word);
        
            vis[i][j]=0;
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        
        int m=board.size(),n=board[0].size();
        
        int pos=0;
        vector<vector<bool>>vis(m+1,vector<bool>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                    if(board[i][j]==word[0]){
                        // cout<<i<<" "<<j<<endl;
                        dfs(i,j,pos,board,vis,word);
                    if(flg)
                            return true;
                flg=false;
                    }
            }
        }
        
        
        return false;
        
    }
};