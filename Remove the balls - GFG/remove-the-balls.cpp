//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        stack<int>stk;
        for(int i=0;i<n;i++){
            bool f=true;
            while(!stk.empty() and color[stk.top()]==color[i] and radius[stk.top()]==radius[i]) {
                stk.pop();
                f=false;
            }
            
            if(f){
                stk.push(i);
            }
        }
        return stk.size();
        
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends