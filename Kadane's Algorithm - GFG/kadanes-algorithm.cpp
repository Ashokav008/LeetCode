// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        
        int glbl=INT_MIN;
        int lcl=0;
        for(int i=0;i<n;i++){
            lcl+=arr[i];
            if(lcl<arr[i])
                lcl=arr[i];
           
                glbl=max(glbl,lcl);
        }
        
        // int maxi=INT_MIN;
        // int meh=0;
        // for(int i=0;i<n;i++){
            
        //      meh+=arr[i];
        //     if(meh<arr[i])
        //         meh=arr[i];
            
        //     maxi=max(meh,maxi);
        // }
        return glbl;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends