// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        map<char,int>mp;
       int n=str.size();
       int i=0,j=0;
       int ans=INT_MAX,curr;
       set<char>st;
       for(int i=0;i<n;i++){
           st.insert(str[i]);
       }
       int sz=st.size();
        for(int i=0;i<n;i++){
            
            mp[str[i]]++;
            
            while(mp[str[j]]>1){
                mp[str[j]]--;
                j++;
                
                // cout<<str[j]<<"  "<<endl;
            }
            if(mp.size()==sz){
                 curr=i-j+1;
                ans=min(ans,curr);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends