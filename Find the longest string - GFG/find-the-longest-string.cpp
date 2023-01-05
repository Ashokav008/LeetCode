//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(),words.end());
        string ans;
        int maxi=0;
        unordered_map<string,int>mp;
        for(auto &it: words){
            mp[it]++;
        }
        int n=words.size();
        for(int i=0;i<n;i++){
            string str=words[i];
            int sz=str.size();
            // cout<<str<<endl;
            string inner="";
            for(int j=0;j<sz;j++){
                inner+=str[j];
                if(mp.find(inner)==mp.end()) 
                     break;
                else if(j==sz-1 and maxi<j+1){
                    ans=str;
                    maxi=j+1;
                }
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends