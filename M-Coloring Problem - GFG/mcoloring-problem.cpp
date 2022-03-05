// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colourbool

bool isPossible(int node,int col,int v,bool graph[101][101],int color[]){
    
    for(int k=0;k<v;k++){
        if(k!=node and graph[k][node]==1 and color[k]==col)
            return false;
    }
    return true;
}

bool solve(int node,int m,int v,bool graph[101][101],int color[]){
    
    
    if(node==v)
        return true;
        
    for(int i=1;i<=m;i++){
        if(isPossible(node,i,v,graph,color)){
            color[node]=i;
            if(solve(node+1,m,v,graph,color)) return true;
            color[node]=0;
        }
    }
    return false;
}




bool graphColoring(bool graph[101][101], int m, int v)
{
    // your code here
    int color[v]={0};
        
    
    
    if(solve(0,m,v, graph,color)) return true;
    
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends