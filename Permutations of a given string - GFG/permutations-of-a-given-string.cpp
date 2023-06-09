//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		set<string>st;
		
		void solve(int i, int n, string s){
		    if(i>=n)
		        return;
		     st.insert(s);
		  //   cout<<s<<endl;
		    for(int idx=i;idx<n;idx++)
		        {
		            swap(s[i],s[idx]);
		            solve(i+1,n,s);
		            swap(s[i],s[idx]);
		        }
		}
		
		vector<string>find_permutation(string s){
	    	vector<string>ans;
	    	int n=s.size();
	    	solve(0,n,s);
	    	for(auto it:st){
	    	  //  cout<<it<<endl;
	    	    ans.push_back(it);
	    	}
	   // 	cout<<endl;
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends