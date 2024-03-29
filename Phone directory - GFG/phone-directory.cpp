//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        
         vector<vector<string>>ans;
         int sz=s.size();
         string str="";
         set<string>st;
         for(int i=0;i<n;i++)
            st.insert(contact[i]);
            
         for(int i=0;i<sz;i++){
             
             str+=s[i];
             vector<string>v;
             int sz1=str.size();
             for(auto s:st){
                 if(sz1<=s.size() and str==s.substr(0,sz1))
                         v.push_back(s);
             }
            sort(v.begin(),v.end());
             if(v.size()==0)
                ans.push_back({"0"});
             else   
                ans.push_back(v);
         }  
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends