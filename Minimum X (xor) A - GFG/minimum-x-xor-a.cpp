//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include <bits/stdc++.h>
 
class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int sbit=__builtin_popcount(b);
        // int mask=((1<<(sbit))-1 );
        // cout<<mask<<endl;
        string ans;
        bitset<32>bset(a);
        // cout<<bset<<endl;
        int i=31;
        while(i>=0  ){
            
            if(bset[i]==1 and sbit ){
                ans+='1';
                sbit--;
            }
            else
                ans+='0';
                
            i--;
        }
         i=31;
        while(sbit){
            if(ans[i]=='0'){
                ans[i]='1';
                sbit--;
            }
            i--;
        }        
        
        // cout<<ans<<endl;
        bitset<32> bsetans(ans);
        // int ff=bsetans.to_ulong();
        int ff=bsetans.to_ulong();
        return ff;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends