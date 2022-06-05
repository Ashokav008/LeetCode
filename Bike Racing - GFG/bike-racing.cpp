// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 int ans;
 long isPossible(int hr,int l,long n,long h[],long a[] ){

  long totalSpeed=0;
     
      
        totalSpeed=0;
        for(int i=0;i<n;i++){
            long currSpeed=(hr*a[i]+h[i]);
            if(currSpeed>=l)
            {
                totalSpeed+=currSpeed;
            }
            
        }
        return totalSpeed;
}

    int bs(int mini,int maxi,long l,long m,long n,long h[],long a[]){
       
        while(mini<=maxi){
            
        long mid=mini+(maxi-mini)/2;
         long speed=isPossible(mid,l,n,h,a);   
        //  cout<<speed<<endl;
        if(speed<=m){
            mini=mid+1;
            
        //   return bs(mid+1,maxi,l,m,n,h,a);
            
        }
        else
        {
            maxi=mid-1;
            // ans=mid;
        //   ans= bs(mini,mid-1,l,m,n,h,a);
           
        }
       
        
        }
        return mini;
    }

    long buzzTime(long n, long m, long l, long h[], long a[])
    {
        // code here
      int maxi=1e9+7;
      return bs(0,maxi, l,m,  n, h, a);
      
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends