// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> arr, int n){
        // code here
        int a,b,c;
        vector<int>ans;
        for(int i=1;i<n-1;i++){
            a=arr[i-1];
            b=arr[i];
            c=arr[i+1];
            
            if(a+b<=c or b+c<=a or a+c<=b)
                    ans.push_back(0);

                else
                    ans.push_back(1);
        }
        
        return ans;
    }
    
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends