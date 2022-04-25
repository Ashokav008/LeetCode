// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int eulerPath(int n, vector<vector<int>> graph){
        // code here
         int evenDeg = 0, oddDeg = 0;
        
        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
                if(graph[i][j]==1) count++;
            }
            
            if(count%2==0) evenDeg++;
            else oddDeg++;
        }
        
        //Is it a Eulerian Circuit?
        if(evenDeg==n) return 1;
        
        
        //If it is not a Eularian Circuit then does
        //it have a single start and end point?
        //If yes then it is an Eulerian path!
        if(oddDeg==2) return 1;
        
        return 0;
        
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                cin>>graph[i][j];
        
        Solution ob;
        cout<<ob.eulerPath(N, graph)<<"\n";
    }
    return 0;
}  // } Driver Code Ends