// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool isCyclic(int node,vector<int>adj[],vector<int>&vis){
      vis[node]=1;
      for(auto child : adj[node]){
          if(!vis[child]){
              if(isCyclic(child,adj,vis))
                return true;
          }
          else{
              if(vis[child]==1)
                return true;
          }
      }
      vis[node]=2;
      return false;
  }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>vis(v,0);
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(isCyclic(i,adj,vis))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends