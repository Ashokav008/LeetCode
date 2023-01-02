//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution{
	public:
	int mod= 1e9+7;
	int power(ll a,ll b) {
        if(b==0) return 1;
        int p = power(a,b/2);
        p = multi(p,p);
        if(b%2==1) p = multi(p,a);
        return p;
    }
	int divide(ll a, ll b){
	    
	  
	     return multi(a,power(b,mod-2));
	}
	
	int multi(ll a, ll b){
	    
	     return (int)(((a%mod)*(b%mod))%mod);
	    
	}
	
	int add(ll a, ll b){
	    
	   return (int)(((a%mod)+(b%mod))%mod);
	}
	int compute_value(int n)
	{
	    vector<int>fact(n+1,0);
	    fact[0]=1;
	    ll ans=0;
	    for(int i=1;i<=n;i++){
	        fact[i]=multi(fact[i-1],i);
	       // cout<<fact[i]<<endl;;
	    }
	    
	    for(int r=0;r<=n;r++){
	        int val=divide(fact[n], multi(fact[n-r] , fact[r]));
	       // cout<<val<<endl;
	        ans=add(ans, multi(val, val));
	       
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
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends