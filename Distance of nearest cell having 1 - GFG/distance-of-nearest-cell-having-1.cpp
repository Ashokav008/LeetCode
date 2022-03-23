// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
            
    bool isValid(int i,int j,int n,int m){
        if(i<0 or j<0 or i>=n or j>=m)
            return false;
            
        return true;
        
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    	int n=grid.size();
	    	int m=grid[0].size();
	    	queue<pair<int,int>>q;
	    	vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1)
	              {
	                  ans[i][j]=0;
	                  q.push({i,j});
	              }
	           
	        }
	    }
	    
	    while(!q.empty()){
	       // cout<<"Iteration"<<endl;
	        int i=q.front().first;
	        int j=q.front().second;
          q.pop();	
            if(isValid(i-1,j,n,m) and ans[i][j]+1<ans[i-1][j] ){
                ans[i-1][j]=ans[i][j]+1;
                q.push({i-1,j});
            }
            if(isValid(i,j-1,n,m) and ans[i][j]+1<ans[i][j-1]){
                ans[i][j-1]=ans[i][j]+1;
                q.push({i,j-1});
            }
            if(isValid(i+1,j,n,m) and ans[i][j]+1<ans[i+1][j]){
                ans[i+1][j]=ans[i][j]+1;
                q.push({i+1,j});
            }
            if(isValid(i,j+1,n,m) and ans[i][j]+1<ans[i][j+1]){
                ans[i][j+1]=ans[i][j]+1;
                q.push({i,j+1});
            }
            
                      
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends