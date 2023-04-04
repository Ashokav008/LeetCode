//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
    // Write your code here.
   int a1=0,a2=0;
    int n=s.size();
    int  i=0;
    while(i<n){
        while(i<n and s[i]=='a')
            i++;
        
        if(i<n and s[i]=='b')
            a1++;
        while(i<n and s[i]=='b')
                i++;
        
        }
        a1+=1;
        i=0;
        
         while(i<n){
            while(i<n and s[i]=='b')
                i++;
            
            if(i<n and s[i]=='a')
                a2++;
                
            while(i<n and s[i]=='a')
                    i++;
            
        }
        a2+=1;
        return min(a1,a2);
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends