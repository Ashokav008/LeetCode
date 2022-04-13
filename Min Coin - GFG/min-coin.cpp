// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    vector<int>dp(amount+1,INT_MAX);
	    
	    dp[0]=0;
	    
	    for(int i=1;i<amount+1;i++){
	        int temp=INT_MAX;
	        for(int j=0;j<nums.size();j++){
	            if(i-nums[j]>=0){
	                temp=min(temp,dp[i-nums[j]]);
	            }
	        }
	        if(temp==INT_MAX)
	            dp[i]=temp;
	        else
	            dp[i]=temp+1;
	        
	    }
	    return dp[amount]==INT_MAX?-1:dp[amount];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends