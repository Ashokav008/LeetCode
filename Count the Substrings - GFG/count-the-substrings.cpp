//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            int cap=0,small=0;
            for(int j=i;j<n;j++){
                if(s[j]>='A' and s[j]<='Z')
                    cap++;
                else
                    small++;
                if(small==cap )
                    ans++;
            }
            
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends