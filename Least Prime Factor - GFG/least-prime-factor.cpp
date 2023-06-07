//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int>ans(n+1,0);
        ans[0]=1;
        ans[1]=1;
        vector<int>prime(n+1,1);

        for(int i=2;i<=n;i++){
            if(prime[i]==1){
                prime[i]=0;
                ans[i]=i;
                for(int j=2*i;j<=n;j+=i){
                    prime[j]=0;
                    if(ans[j]==0)
                        ans[j]=i;
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends