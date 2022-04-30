// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string s, vector<vector<int>>query){
	    // Code here
	    vector<int>ans;
	    for(auto q:query)
	    {
	       int cnt=0;
	        vector<int>v(26,0);
	        for(int i=q[0]-1;i<q[1];i++){
	            if(v[s[i]-'a']!=1)
	                {
	                    v[s[i]-'a']=1;
	                    cnt++;
	                }
	        }
	        ans.push_back(cnt);
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends