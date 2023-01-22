//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        int n=s.size();
        stack<char>stk;
        stk.push(s[0]);
        int i=1;
       for(int i=1;i<n;i++){
           if(!stk.empty() and stk.top()==s[i]){
               stk.pop();
           }
           else
            stk.push(s[i]);
       }
       if(stk.empty())
        return "-1";
       string ans;
       while(!stk.empty()){
           ans+=stk.top();
           stk.pop();
           
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends