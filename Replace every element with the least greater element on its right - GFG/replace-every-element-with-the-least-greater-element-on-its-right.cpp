//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        
        map<int,int>mp;
        vector<int>vec(n);
        vec[n-1]=-1;
        mp[arr[n-1]]++;
        for(int i=n-2;i>=0;i--){
            
            auto it=mp.lower_bound(arr[i]+1);
            
                if(it!=mp.end())
                     vec[i]=(it)->first;
                else if(it->first==mp.size())
                    vec[i]=-1;
                    
              mp[arr[i]]++;  
            
        }
        // cout<<endl;
        return vec;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends