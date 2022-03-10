// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isPatternPresent(string S, string P) {
   string match="";
        int i=0;
        int n=S.length();
        int m=P.length();
        if(m>n)
        return 0;
        if(P[0]=='^')
        {
            string s=P.substr(1,m);
            string c=S.substr(0,m-1);
           
            return s==c? 1:0;
            }
        else if(P[m-1]=='$')
        {
            string s=P.substr(0,m-1);
            string c=S.substr(n-m+1,n);
           
            return s==c? 1:0;
        }
        else{
            return S.find(P)!=-1;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string P,S;

        cin>>P;
        cin>>S;

        Solution ob;
        cout << ob.isPatternPresent(S,P) << endl;
    }
    return 0;
}  // } Driver Code Ends