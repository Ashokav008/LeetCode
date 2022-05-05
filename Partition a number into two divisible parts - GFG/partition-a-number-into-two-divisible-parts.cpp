// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string s, int a, int b){
        // code here 
        string s1,s2;
        int n=s.size();
        
        for(int i=1;i<n;i++)
        {
            s1=s.substr(0,i);
            s2=s.substr(i,n-i);
            // cout<<s1<<" "<<s2<<endl;
            if(stoi(s1)%a==0   and stoi(s2)%b==0){
                break;
            }
            
        }
        
        if(stoi(s1)%a==0 and stoi(s2)%b==0)
            return s1+" "+s2;
        
        else
            return "-1";
       
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends