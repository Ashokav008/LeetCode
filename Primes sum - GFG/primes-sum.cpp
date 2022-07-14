// { Driver Code Starts

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  
 bool isPrime(int n)
{
    if (n <= 1)
        return false;
 
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
  
    string isSumOfTwo(int n){
        
     
     set<int>st;
     for(int i=2;i<n;i++){
         if(isPrime(i)){
            //  cout<<i<<endl;
            st.insert(i);
         }
         }
     
    for(auto it:st){
        if(st.find(n-it)!=st.end())
            return "Yes";
    }     
    return "No";
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}
  // } Driver Code Ends