// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
      int help(int a)
       {
            int temp = a; 
            int res = 0; 
            for(int i = 5; i <= a; i *=5 ){ 
                res += temp/i; 
            } 
            return res;
       }
       int findNum(int n)
       {
          int l=0;
          int h=5*n;
          int ans=0;
          while(l<=h)
          {
              int m = (l+h)/2;
              int zeroes = help(m);
              if(zeroes >= n)
              {
                  ans=m;
                  h=m-1;
              }
              else 
                l=m+1;
          }
        
           return ans;
       }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends