// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        char f,s;
        int n=a.size();
         set<char>st;
         unordered_map<char,bool>mp;
         string req="";
         for(int i=0;i<n;i++){
             st.insert(a[i]);
         }
         for(auto it:st)
            req+=it;
       int i=0 ;
       int j=0;
      for(int i=0;i<n;i++)
       {
         
            if(mp[a[i]])
               {
                  continue;
               }
              else if(a[i]<=req[j]){
                  mp[a[i]]=true;
                  j++;
                  if(j==req.size())
                        return a;
                
                continue;
              }
              else{
                  f=a[i],s=req[j];
                  break;
              }
           
       }
       
       
       for(int i=0 ;i< n; i++)
       {
           if(a[i]==f)
           a[i]=s ;
           else if(a[i]==s)
           a[i]=f;
       }
       return a ;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends