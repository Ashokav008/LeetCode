class Solution {
public:
    
    vector<vector<int>>ans;
  
   
    void dfs(int node,vector<int>v,int n,vector<bool>vis,vector<vector<int>>& arr){
        
      vis[node]=true;
        v.push_back(node);
        if(node==n-1)
        {
            ans.push_back(v);
            return;
        }
        
       
        for(auto child:arr[node]){
            
            if(!vis[child])
                dfs(child,v,n,vis,arr);
        }
        
        vis[node]=false;
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        
        int n=graph.size();
        vector<bool>vis(n,false);
       
        vector<int>v;
        // arr=graph;
        dfs(0,v,n,vis,graph);
        
        return ans;
        
        
        
    }
};