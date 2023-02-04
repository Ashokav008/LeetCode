//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  class DSU{
    public :
    vector<int>par,rank,size;
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1,1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            size[i]=1;
        }
    }
    
    int findPar(int node){
        if(par[node]==node)
            return node;
        
        return par[node]=findPar(par[node]);
    }

    void unionByRank(int u, int v){
        
        int p1=findPar(u);
        int p2=findPar(v);
        
        if(p1==p2)
            return ;
        else if(rank[p1]<rank[p2]){
            par[p1]=p2;
        }
        else  if(rank[p2] < rank[p1]){
            par[p2]=p1;
        }
        else{
            par[p1]=p2;
            rank[p2]++;
        }       
    } 
    
    void unionBySize(int u, int v){
        int p1=findPar(u);
        int p2=findPar(v);
        if(p1==p2)
            return;
        if(size[p1]<size[p2]){
            par[p1]=p2;
            size[p2]+=size[p1];
        }else{
            par[p2]=p1;
            size[p1]+=size[p2];
        }
    }
};

  
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int r=INT_MIN,c=INT_MIN;
        
        for(auto it: stones){
            r=max(r,it[0]);
            c=max(c,it[1]);
        }
        
        DSU ds(r+c+1);
        unordered_map<int,int>mp;
        for(auto it: stones){
            int r1=it[0];
            int c1=it[1]+ r+1;
            mp[r1]=1;
            mp[c1]=1;
            ds.unionByRank(r1,c1);
        }
        int cnt=0;
        for(auto it:mp){
            if(ds.findPar(it.first)==it.first)
                cnt++;
        }
        
        return n-cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends