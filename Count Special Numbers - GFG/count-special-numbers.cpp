//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    unordered_set<int>st;
    int countSpecialNumbers(int n, vector<int> arr) {
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            
                mp[arr[i]]--;
               if(mp[arr[i]]==0)
                mp.erase(arr[i]);
                
            for(int d=1;d<=sqrt(arr[i]);d++){
             
               if(arr[i]%d==0){
                   if(mp.find(arr[i]/d)!=mp.end() or mp.find(d)!=mp.end())
                   {
                       ans++;
                       break;
                   }
               }
            }
            mp[arr[i]]++;
            
        }
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends