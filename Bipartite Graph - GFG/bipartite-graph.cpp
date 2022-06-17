// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool solve(int i, vector<int>adj[],vector<int>&colored){
        
       queue<int>q;
	    q.push(i);
	    colored[i]=0;
	    while(!q.empty()){
	        int front=q.front();
	         q.pop();
	        int fcolor=colored[front];
	        
	        for(auto i:adj[front]){
	            if(colored[i]==-1){
	                  q.push(i);
	                colored[i]=1-fcolor;
	              
	            }
	            else if(colored[i]==fcolor){
	                return false;
	            }
	        }
	       
	        
	    }
	    return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	  vector<int>colored(V,-1);
	 for(int i=0;i<V;i++){
	    if(colored[i]==-1){
         if(!solve(i,adj,colored))
                return false;
    	  
	    }
	 }
	 return true;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends