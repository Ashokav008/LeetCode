// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int shortestPath( int x, int y){ 
           int s=0; 
        while(x!=y){
            if(x>y)
            x/=2;
            else if(y>=x)
                y/=2;
                
            s++;
         }
         
        return s;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends