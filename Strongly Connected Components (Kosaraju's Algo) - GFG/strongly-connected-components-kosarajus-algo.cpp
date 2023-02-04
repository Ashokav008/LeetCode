//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	
	void simpleDfs(int i , vector<int>adjR[],vector<int>&vis){
	    vis[i]=1;
	    for(auto it: adjR[i]){
	        if(!vis[it])
	            simpleDfs(it, adjR, vis);
	    }
	}
	
	void cDfs(int i, vector<int>&vis, vector<int> adj[],stack<int>&stk){
	    
	    vis[i]=1;
	    for(auto next: adj[i]){
	        if(!vis[next])
	            cDfs(next, vis, adj,stk);
	    }
	    
	    stk.push(i);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        // Step 1: store node in decreasing order of their time of dfs completion
        
        stack<int>stk;
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cDfs(i, vis, adj,stk); //used for sort nodes according to their dfs completion time.
            }
        }
        // while(!stk.empty()){
        //     cout<<stk.top()<<endl;
        //     stk.pop();
        // }
        //Step 2 : reverse the graph .. 
        
        vector<int>adjR[n];
        for(int i=0;i<n;i++){
            vis[i]=0; //resetting vis vector for step 3 vali dfs..
            for(auto it : adj[i]){
                adjR[it].push_back(i);
            }
        }
        // step 3 : traverse the reversed graph according stk nodes.
        int scc=0;
        while(!stk.empty()){
            
            int f=stk.top();
            stk.pop();
            
            
                if(!vis[f]){
                    scc++;
                    simpleDfs(f, adjR,vis);
                }
            
        }
        return scc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends