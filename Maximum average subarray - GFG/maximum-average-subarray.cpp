// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
 int findMaxAverage(int arr[], int n, int k) {
      
      double ans =INT_MIN,sum=0;
      int idx,j=0;
      
      for(int i=0;i<n;i++)
      {
         if(i<k-1) sum+=arr[i];
         
         else
         {
             sum+=arr[i];
             
             if((sum/k)>ans)
             {
                 idx = i+1-k;
                 ans = sum/k;
             }
             sum-=arr[j];
             j++;
             
         }
          
      }
      return idx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends