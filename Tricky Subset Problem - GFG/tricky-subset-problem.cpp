// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long s, long long n, long long x, long long a[])
    {
        // code here
    
     vector<long long>ans;
     ans.push_back(s);
     long long sum=s;
     for(int i=0;i<n;i++){
         if(sum>x)
            break;
         ans.push_back(sum+a[i]);
        sum+=ans.back();
     }
   for(long long int i = ans.size() - 1; i >= 0; i--)
    {
    if(ans[i] > x)
    continue;
    else
    {
    x -= ans[i];
    }
    if(x == 0)
    return 1;
    }
    return x==0;
    }
  
    
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends