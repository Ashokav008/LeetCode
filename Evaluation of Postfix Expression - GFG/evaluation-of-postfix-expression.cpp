// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string str)
    {
        // Your code here
        stack<int>stk;
        int n=str.size();
        
        for(int i=0;i<n;i++){
            if(str[i]>='0' and str[i]<='9'){
                stk.push(str[i]-'0');
            }
            else{
                int x=stk.top();
                stk.pop();
                int y=stk.top();
                stk.pop();
                int ans;
                if(str[i]=='+'){
                   ans=x+y;                             
                }
                
                 if(str[i]=='-'){
                   ans=y-x;                             
                }
                
                 if(str[i]=='*'){
                   ans=x*y;                             
                } 
                
                if(str[i]=='/'){
                   ans=y/x;                             
                }
            stk.push(ans);
            }
            
        }
        return stk.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends