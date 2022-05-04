// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends

static bool comp(pair<int,int>&p1,pair<int,int>&p2){
    
 
    
     if(p1.first==p2.first)
        return p1.second<p2.second;
     
        return p1.first<p2.first;
}


vector<int> permute(vector<vector<int>> &arr, int n)
{
    
    // Complete the function
    vector<pair<int,int>>v;
    
    for(int i=0;i<n;i++){
        v.push_back({arr[i][0]+arr[i][1],i+1});
    }
    sort(v.begin(),v.end(),comp);
    
    vector<int>ans;
    for(auto it:v){
        ans.push_back(it.second);
    }
    
    return ans;
    
    
}