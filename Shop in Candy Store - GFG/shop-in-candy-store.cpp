// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        sort(candies,candies+n);
      
       
        int mini=0;
        int n2=n;
        for(int i=0;i<n2;i++){
            mini+=candies[i];
            n2=n2-k;
        }
        int maxi=0;
        int n1=0;
        for(int i=n-1;i>=n1;i--){
            // cout<<i<<endl;
               maxi+=candies[i];
               n1=n1+k;
        }
        vector<int>v;
        v.push_back(mini);
        v.push_back(maxi);
        
        return v;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends