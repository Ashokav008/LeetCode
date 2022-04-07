// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n){
      if(n==0)
           return "-1";
       else if(n==1)
           return ar[0];
       // sort array and compare between first and last string 
       sort(ar,ar+n); 
       string a=ar[0],b=ar[n-1];
       int len=0;
       while(len<a.length() && a[len]==b[len])
           len+=1;
       if(len==0)
       return "-1";
       return a.substr(0,len);
   }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends