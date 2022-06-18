// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:

    bool isCycle(int node,int parent,vector<int>adj[],vector<int>&vis){
        
        vis[node]=1;
      
        for(auto it:adj[node]){
            if(!vis[it]){
                 if(isCycle(it,node,adj,vis))
                return true;
            }
            else
                 if(it!=parent)
                        return true;                
        }
        return false;
        
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int>vis(v,0);
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
               bool flg= isCycle(i,-1,adj,vis);
                  if(flg)
                      return true;
            }
            
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends