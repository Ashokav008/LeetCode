//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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

class Solution {
  public:
    
    bool isValid(int i, int j , int n){
        if(i>=0 and j>=0 and i<n and j<n)
            return true;
        return false;
    }
  
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DSU ds(n*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        //step 1 : Connect the component
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    continue;
                for(int k=0;k<4;k++){
                    int newr=i+dr[k];
                    int newc=j+ dc[k];
                    if(isValid(newr,newc,n) and grid[newr][newc]==1){
                        int nodeNo=i*n + j;
                        int adjNodeNo=newr*n+ newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
    int mx=0;
    //step 2:  fill one cell and check for the adjectn cells for making large islands
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    continue;
                set<int>components;
                for(int k=0;k<4;k++){
                    int newr=i+dr[k];
                    int newc=j+ dc[k];
                    if(isValid(newr,newc,n) and grid[newr][newc]){
                       components.insert(ds.findPar(newr*n+newc));
                    }
                }
                int sz=0;
                for(auto it: components){
                    sz+=ds.size[it];
                }
                mx=max(mx,sz+1);
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx, ds.size[ds.findPar(i)]);
            
        }
        return mx;
    
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends