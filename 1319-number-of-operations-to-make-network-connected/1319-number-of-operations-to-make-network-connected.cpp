class Solution {
public:
    void dfs(int i,vector<int>adj[],vector<bool>&vis){
        
        vis[i]=true;
        
        for(auto child:adj[i]){
            if(!vis[child])
                dfs(child,adj,vis);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
     
        vector<int>adj[n];
        
        int m=con.size();
        if(m<n-1)
            return -1;
        
        for(int i=0;i<m;i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
            
        }
        
        
        vector<bool>vis(n,0);
        
        int cnt=0;
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                    cnt++;
                    dfs(i,adj,vis);
                }
        }
        return cnt-1;
    }
};