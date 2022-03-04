class Solution {
public:
    
    vector<vector<int>>ans;
   vector<vector<int>>arr;
   
    void dfs(int node,vector<int>v,int n,vector<bool>vis){
        
      vis[node]=true;
        v.push_back(node);
        if(node==n-1)
        {
            ans.push_back(v);
            return;
        }
        
       
        for(auto child:arr[node]){
            
            if(!vis[child])
                dfs(child,v,n,vis);
        }
        
        vis[node]=false;
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        
        int n=graph.size();
        vector<bool>vis(n,false);
       
        vector<int>v;
        arr=graph;
        dfs(0,v,n,vis);
        
        return ans;
        
        
        
    }
};