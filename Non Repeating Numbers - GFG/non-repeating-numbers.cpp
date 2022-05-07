// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xor1=0,n=nums.size();
        for(int i=0;i<n;i++)
            xor1^=nums[i];
            
        int RightMostSetBit=xor1  & ~(xor1-1);
        
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            
            if((nums[i] & RightMostSetBit)==0)
                ans1^=nums[i];
            else
                ans2^=nums[i];
        }
        
        vector<int>ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends