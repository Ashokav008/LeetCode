// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
void rev(stack<int> stk, vector<int>&ans){
    
    if(stk.size()==0)
        return;
    int ele=stk.top();
    stk.pop();
    ans.push_back(ele);
    rev(stk,ans);
    
    return;
}

    vector<int> Reverse(stack<int>st){
        
        vector<int>ans;
        rev(st,ans);
        
        return ans;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends