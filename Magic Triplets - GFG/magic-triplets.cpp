//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    int ans=0;
	    int n=nums.size();
	    for(int i=1;i<n-1;i++){
	       int l=i-1,r=i+1;
	       int lcnt=0,rcnt=0;
	       
    	       while(l>=0){
    	           
    	           if(nums[l]<nums[i])
    	            lcnt++;
    	            
    	            l--;
    	       }
    	       while(r<n){
    	           if(nums[i]<nums[r] )
    	                rcnt++;
    	            r++;
    	       }
    	       
    	      ans+=(rcnt*lcnt);
	        }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends