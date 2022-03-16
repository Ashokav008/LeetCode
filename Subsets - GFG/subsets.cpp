// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void solve(int index,vector<int>&arr,int n,vector<int>&v, vector<vector<int>>&ans){
        
        ans.push_back(v);
        
        for(int i=index;i<n;i++){
        // cout<<arr[i]<<" "<<endl;
            v.push_back(arr[i]);
            solve(i+1,arr,n,v,ans);
            v.pop_back();
        }
       return;
    }
    
    
    vector<vector<int> > subsets(vector<int>& arr)
    {
        //code here
        vector<int>v;
        vector<vector<int>>ans;
        // sort(arr.begin(),arr.end());
        int n=arr.size();
        int i=0;
        solve(i,arr,n,v,ans);
         sort(ans.begin(),ans.end());
        return  ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends