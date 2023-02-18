//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        
        int j=0,cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='O')
                cnt++;
            while(cnt>m and j<n)
                {  
                    if(arr[j]=='O')
                        cnt--;
                        
                    j++;
                }
            ans=max(ans, i-j+1);
                
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends