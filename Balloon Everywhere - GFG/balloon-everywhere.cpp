//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char,int>mp;
        for(auto it:s)
            mp[it]++;
            
        int ans=INT_MAX;
        for(auto it: mp){ 
            if(it.first=='b' or it.first=='a'  or it.first=='l' or it.first=='o' or it.first=='n'){ 
            if(it.first=='o' or it.first=='l')
                ans=min(ans, (it.second)/2);
            else
                ans=min(ans, it.second);
             }
        }
        return ans;
            
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends