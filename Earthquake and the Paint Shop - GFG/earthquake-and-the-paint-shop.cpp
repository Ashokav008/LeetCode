//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int n, vector<string> a) {
        // code here
        vector<alphanumeric>ans;
        sort(a.begin(),a.end());
        int cnt=1;
        
        // ans.push_back(a[0]);
        for(int i=1;i<n;i++){
            
            if(a[i]==a[i-1])
                {
                    // cout<<"same"<<"  "<<endl;
                    cnt++;
                }
           else{
            //   cout<<"No Same"<<endl;
               ans.push_back({a[i-1],cnt});
               cnt=1;
           }
       
        }
            // cout<<"FInal  "<<endl;
            ans.push_back({a[n-1],cnt});
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends