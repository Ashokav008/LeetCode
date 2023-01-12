//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int n, vector<int> arr) {
        // code here
        priority_queue<int ,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        int ans=0;
        
        while(pq.size()>1){
            
            int t1=pq.top();
            pq.pop();
            int t2=pq.top();
            pq.pop();
            ans+=(t1+t2);
            // cout<<ans<<endl;
            pq.push(t1+t2);
        }
        // if(pq.size()==1)
        //     ans+=pq.top();
            
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends