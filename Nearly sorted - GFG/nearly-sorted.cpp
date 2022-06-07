// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
        vector<int>ans;
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            if(i<k){
               mp[arr[i]]++;
               continue;
            }
            mp[arr[i]]++;
            auto it=mp.begin();
            if(it->second ==1 ){
                ans.push_back(it->first);
                mp.erase(it);
            }
            else
            {
                mp[it->first]--;
            }
            
        }
        for(auto it:mp){
            // cout<<it.first<<endl;
            ans.push_back(it.first);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends