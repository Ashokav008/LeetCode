//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        int n=a.size(),m=b.size();
        string str=a;
        int rep=m/n;
        int i=1;
        while(i<rep){
            str+=a;
            i++;
        }
        // cout<<str<<endl;
        if(str.find(b)!=string::npos){
            return rep;
        }
        
        // if(str.find(b)!=string::npos){
        //     return 3;
        // }
        str+=a;
        if(str.find(b)!=string::npos){
            return rep+1;
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.

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
}
// } Driver Code Ends