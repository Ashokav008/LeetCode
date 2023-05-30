//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int n,m;

    bool solve(int i, int j, int idx,vector<vector<char>>& board, vector<vector<int>>&vis, string &word){
        if(idx==word.size())
            return true;
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j]==1)
            return false;
        if(board[i][j]!=word[idx])
            return false;
        vis[i][j]=1;
        
        // cout<<idx<<endl;
        bool r=solve(i+1,j,idx+1,board,vis,word);
        bool b=solve(i,j+1,idx+1,board,vis,word);
        bool l=solve(i-1,j,idx+1,board,vis,word);
        bool u=solve(i,j-1,idx+1,board,vis,word);
        return r or b or l or u;
        
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int i=0,j=0;
        n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
               if(board[i][j]==word[0]  ){
                   vector<vector<int>> vis(n,vector<int>(m,0));
                   if(solve(i,j,0,board,vis,word))
                   return true;
               }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends