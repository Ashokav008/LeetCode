// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
int kadane(vector<int> &v){
       int max_so_far = v[0];
       int curr_so_far = v[0];
       for(int i = 1; i < v.size(); i++){
           curr_so_far = max(v[i],curr_so_far+v[i]);
           max_so_far = max(max_so_far,curr_so_far);
       }
       return (max_so_far);
   }
  
    int maximumSumRectangle(int r, int c, vector<vector<int>> m) {
        // code here
        
        int ma=INT_MIN;
      for(int i=0;i<r;i++){
            vector<int>ans(c,0);
        for(int j=i;j<r;j++){
           
            for(int k=0;k<c;k++){
                
                ans[k]+=m[j][k];
                
            }
             ma=max(ma,kadane(ans));
        }
      }
        return ma;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends