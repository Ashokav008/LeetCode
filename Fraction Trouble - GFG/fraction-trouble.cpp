// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
        
        double fraction=(double)n/d;
        
        int n1=10000,n2=10000;
        
          double ans = 0;
          int ans1,ans2;
          while(n1>0){
              double tempF=(double)n1/n2;
              if(tempF>=fraction)
                    n1--;
            else{
                
                if(tempF>ans){
                    ans=tempF;
                    ans1=n1;
                    ans2=n2;
                }
                    n2--;
            }
          }
        return {ans1,ans2};
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends