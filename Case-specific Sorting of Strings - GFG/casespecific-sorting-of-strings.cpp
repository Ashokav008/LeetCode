//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string l="",u="";
        for(int i=0;i<n;i++){
            if(str[i]>='a'   and str[i]<='z')
                l+=str[i];
            else
                u+=str[i];
        }
        sort(u.begin(),u.end());
        sort(l.begin(),l.end());
        
        int li=0,ui=0;
        for(int i=0;i<n;i++){
            if(str[i]>='a' and str[i]<='z'){
                str[i]=l[li++];
            }
            else{
                str[i]=u[ui++];
            }
        }
        
        
        return str;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends