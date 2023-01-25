//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DSU{
    public :
    vector<int>par,rank;
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;
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
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& conn) {
          DSU ds(n);
            int extra=0;
            for(auto it:conn){
                int p1=ds.findPar(it[0]);
                int p2=ds.findPar(it[1]);
                if(p1==p2)
                    extra++;
                else
                     ds.unionByRank(it[0],it[1]);
            }
            int components=0;
            for(int i=0;i<n;i++)
                if(ds.par[i]==i)
                    components++;

           int ans=components-1;
            if(extra>=ans)
                return ans;
            return -1;

    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends