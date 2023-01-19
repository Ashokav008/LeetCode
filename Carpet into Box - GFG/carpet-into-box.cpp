//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        if(c>d)
            swap(c,d);
        if(a>b)
            swap(a,b);
    int ans=0;
    while(a>c or b>d){

        if(a>c and b>d){
            b/=2;
            ans++;
        }
        if(a>b)
            swap(a,b);
            
        else if(a>c ){
            a/=2;
            ans++;
            
        }
         if(a>b)
            swap(a,b);
        else if(b>d){
            b/=2;
            ans++;
        }
        if(a>b)
            swap(a,b);
      
    }
        return ans;
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends