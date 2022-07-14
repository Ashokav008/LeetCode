class Solution {
public:
    int ans=0;
    
    bool isPossible(int i,int j,vector<vector<int>>&vis){
        
        if( i<0 or j<0 or  i>=vis.size() or j>=vis[0].size() or vis[i][j]==1 )
            return false;
        
        return true;
                
    }
    
    void dfs(int i,int j , vector<vector<int>>&vis){
        
        vis[i][j]=1;
        
        if(i==vis.size()-1 and j==vis[0].size()-1){
            cout<<i<<"  "<<j<<endl;
            ans++;
            vis[i][j]=0;
            return;
        }
        
        if(isPossible(i+1,j,vis)){
            dfs(i+1,j,vis);
        }
        
        if(isPossible(i,j+1,vis)){
            dfs(i,j+1,vis);
        }
        vis[i][j]=0;
    }
    
    int uniquePaths(int m, int n) {
     ans=0;
      vector<vector<int>>vis(m+1,vector<int>(n+1,1)) ;
        int mod=1e9+7;
        // dfs(0,0,vis);
        for(int i=1;i<m;i++){
            
            for(int j=1;j<n;j++){
                vis[i][j]=vis[i-1][j]+vis[i][j-1];
                
                
            }
            
        }
        
        
        return vis[m-1][n-1];
        
    }
};