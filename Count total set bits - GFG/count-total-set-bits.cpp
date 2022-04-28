// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    
    int highestPower(int n){
        
        int x=0;
        int i=1;
        while((1<<x)<=n)
            x++;
        
        return x-1;
    }
    
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        if(n<=1)
            return n;
            
        int x=highestPower(n);
        
        return (x*pow(2,(x-1)))+(n-pow(2,x)+1)+countSetBits(n-pow(2,x));
        
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends