// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        
        int n=a.size(),m=b.size();
        unordered_set<char>st;
        
        for(int i=0;i<a.size();i++){
           
            st.insert(a[i]);
        }
        
        for(int i=0;i<b.size();i++){
            // cout<<b[i]<<endl;
            if(st.find(b[i])==st.end())
                return -1;
        }
       int add=m/n;
       if(m%n==0)
            add--;
       string str=a;
       for(int i=0;i<add;i++){
           str+=a;
       }
        
    // cout<<add<<" " <<str<<"  "<<b<<endl;
     int sz=str.find(b);
    if(sz!=string::npos)
    return add+1;
    str+=a;
    
       sz=str.find(b);
    if(sz!=string::npos)
        return add+2;
    
        
    return -1;    
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends