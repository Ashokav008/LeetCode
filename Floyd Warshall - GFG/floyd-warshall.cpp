// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&g){
	    // Code here
	    int n=g.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(g[i][j]==-1)
	                g[i][j]=INT_MAX;
	           
	        }
	    }
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                
	                if(i==k or j==k or g[i][k]==INT_MAX or g[k][j]==INT_MAX)
	                    continue;
	                g[i][j]=min(g[i][j] , g[i][k]+g[k][j]);
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++)
	            if(g[i][j]==INT_MAX)
	                g[i][j]=-1;
	    }
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends