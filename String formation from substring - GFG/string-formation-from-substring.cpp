// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string getStr(int times,string str){
	    string temp;
	    while(times--){
	        temp+=str;
	    }
	    return temp;
	}	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	    int n=s.length();
	    
	    
	    for(int i=1;i<=n/2;i++){
	        
	    if(n%i==0){
	        if(getStr(n/i,s.substr(0,i))==s)
	            return 1;
	    }
	     
	    }
	    return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends