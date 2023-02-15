//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

  void solve(int i, int j ,int h,vector<vector<int>>& heights, vector<vector<bool>>&vis){
        
        if(i<0 or j<0 or i>=heights.size() or j>=heights[0].size() or vis[i][j] or heights[i][j] <h )
            return;
        //  cout<<"cal for "<<i<<"  "<<j<<endl;
       int ht=heights[i][j];
       vis[i][j]=1;
       solve(i+1,j,ht,heights, vis);
       solve(i,j+1,ht,heights, vis);
       solve(i-1,j,ht,heights, vis);
       solve(i,j-1,ht,heights, vis);
    }

    int water_flow(vector<vector<int>> &heights,int n,int m){

    // int n=heights.size(),m=heights[0].size();
        vector<vector<bool>>pac(n,vector<bool>(m,false)) ;
        vector<vector<bool>>atl(n,vector<bool>(m,false)) ;

        for(int i=0;i<n;i++){
            solve(i,0,-1,heights,pac);
            solve(i,m-1,-1,heights,atl);
        }


        for(int j=0;j<m;j++){
            solve(0,j,-1,heights,pac);
            solve(n-1,j,-1,heights,atl);
        }
    // vector<vector<int>>ans;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pac[i][j] and atl[i][j]){
                ans++;
            }
        }
    }
    return ans;
    
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends