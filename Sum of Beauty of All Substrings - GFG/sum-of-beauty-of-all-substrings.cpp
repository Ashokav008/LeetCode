//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            vector<int>v(26,0);
            for(int j=i;j<n;j++){
                
                  v[s[j]-'a']++;
                    
                int mini=INT_MAX,maxi=INT_MIN;
                 for(int k=0;k<26;k++){
                      if(v[k]>0)
                      {
                          maxi=max(maxi, v[k]);
                          mini=min(mini, v[k]);
                      }
                  }
                  ans+=(maxi-mini);
            }
           
           v.clear();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends