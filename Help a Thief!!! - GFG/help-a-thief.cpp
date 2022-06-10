// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  static bool comp(pair<int,int> a, pair<int,int> b)
   {
       return a.first > b.first;
   }
   int maxCoins(int a[], int b[], int t, int n) {
       vector <pair<int,int>> v;
       for (int i=0; i<n; i++)
       {
           v.push_back({b[i],a[i]});
       }
       
       sort (v.begin(), v.end(), comp);
       
       int x = 0;
       for (int i=0; i<n; i++)
       {
           if (t==0)
               break;
           
           x += (min(t, v[i].second)*v[i].first);
           t -= min(t, v[i].second);
       }
       
       return x;
   
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends