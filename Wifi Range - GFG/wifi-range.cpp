//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string str, int x){
        
        x*=2;
        int cnt=0;
        int i=0;
        while(i<n and str[i]=='0'){
            cnt++,i++;
        }
        if(cnt>x/2)
            return false;
            
        while(i<n){
            while(str[i]=='0'){
                cnt++;
                i++;
            }
            if(i==n and cnt>x/2){
                return false;
            }
            if(cnt>x)
                return false;
            cnt=0;
            i++;
        }
        return true;
        
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends