// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxDepth=0;
    void dfs(int node,int parent,vector<vector<int>>&adj,int depth){
        
        maxDepth=max(maxDepth,depth);
        for(auto child:adj[node]){
            if(child!=parent)
                dfs(child,node,adj,depth+1);
        }
        
    }

    int partyHouse(int N, vector<vector<int>> &adj){
        // code here
        
        int ans=1e9;
        for(int i=1;i<=N;i++){
            maxDepth=0;
            dfs(i,-1,adj,0);
            ans=min(ans,maxDepth);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends