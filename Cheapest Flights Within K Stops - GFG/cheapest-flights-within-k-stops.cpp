//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        
        vector<pair<int,int>>adj[n];
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int, pair<int,int> >>q;
            // stops src cost
        q.push({0, {src,0}});
        
        vector<int>dist(n,1e8);
        dist[src]=0;
        
        while(!q.empty()){
            
            auto front=q.front();
            int stops=front.first;
            int node=front.second.first;
            int cost=front.second.second;
            q.pop();
            if(stops>k)
                continue;
                
            for(auto &itr: adj[node]){
                int next=itr.first;
                int weight=itr.second;
                if(cost+ weight<dist[next] ){
                    dist[next]=cost+weight;
                    q.push({stops+1, {next,cost+weight}});
                }
            }
            
        }
        
        
        
        if(dist[dst]==1e8)
            return -1;
            
        return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends