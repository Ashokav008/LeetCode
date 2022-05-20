// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int findTime(string S1, string S2) {
       // code here
       int s=0,t=0;
       unordered_map<char,int>ump;
       for(int i=0; i<S1.length(); i++)
       {
           ump[S1[i]]=i;
       }
       int m=0;
       for(auto x : S2)
       {
           s=m;
           if(ump.find(x)!=ump.end())
           {
               m=ump[x];
               s=abs(s-m);
           }
           t+=s;
       }
       return t;
   }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends