// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k)
                cnt++;
        }
        int maxValid=0;
        int window=cnt;
        int valid=0;
        for(int i=0;i<n;i++){
        if(i<window){
                if(arr[i]<=k)
                    valid++;
                 maxValid=max(maxValid,valid);
            }
        else{
            if(arr[i]<=k)
                valid++;
            if(arr[i-window]<=k)
                valid--;
        maxValid=max(maxValid,valid);
        }
        }
        
        return window-maxValid;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends