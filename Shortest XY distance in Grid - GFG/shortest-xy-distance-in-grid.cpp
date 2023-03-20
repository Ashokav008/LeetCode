//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    

  
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
       
        vector<pair<int,int>>drs{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front().first.first;
                int y=q.front().first.second;
                int dist=q.front().second;
                q.pop();
                if(grid[x][y]=='Y'){
                    return dist;
                }
                for(auto dr : drs){
                    int dx=dr.first,dy=dr.second;
                    int i=x+dx,j=y+dy;
                    if(i<0 or j<0 or i>=n or j>=m or vis[i][j])
                        continue;
                    q.push({{i,j},dist+1});
                    vis[i][j]=1;
                    
                }
                
                
            }
        }
        return INT_MAX;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends