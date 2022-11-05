//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
   vector<int>coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
    
    void solve(int i, int n, vector<int>&ans ){
        
        if(i<0)
            return ;
        if(n<=0)
            return ;
        
        if(coins[i]<=n){
            // cout<<i<<endl;
            
            ans.push_back(coins[i]);
            solve(i, n-coins[i],ans);
        }
        else{
            solve(i-1, n, ans);
        }
    }

    vector<int> minPartition(int n)
    {
        vector<int>ans;
        
        solve(9, n, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends