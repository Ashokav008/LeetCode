class Solution {
public:
    bool bfs(int node,  vector<int>&vis,vector<vector<int>>& graph){
        queue<int>q;
        q.push(node);
        vis[node]=0;
       while(!q.empty()){
            int node=q.front();
            q.pop();
            int fcolor=vis[node];
            
            for(auto it:graph[node]){
                // for(auto it:adj)
                   
                
                    if(vis[it]==-1){
                         q.push(it);
                    vis[it]=1-fcolor;
                    }
                else if( vis[it]==fcolor)
                            return false;
                // 
                
            }
        }
        return true;
         
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
       
        int n=graph.size();
        // int color=1;
        vector<int>vis(n,-1);
       
        bool ans=true;
        for(int i=0;i<n;i++){
            if(vis[i]==-1)
                    ans  = bfs(i,vis,graph);
            if(ans==false)
                    return false;
        }
        
        return true;
        
    }
};