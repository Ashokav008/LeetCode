// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string S){
        
        string x=S;
        string y ;
        reverse(S.begin(),S.end());
        y=S;
        int m=x.size();
      
           vector<vector<int>>t(m+1,vector<int>(m+1,0));
        // cout<<x<<"   "<<y<<endl;
        //initilization code
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=m;j++){
        //         if(i==0 or j==0)
        //             t[i][j]=0;
        //     }
        // }
        
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                
                if(x[i-1]==y[j-1])
                    t[i][j]=1+ t[i-1][j-1];
                
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
           
        //   cout<<m-t[m][m]<<endl;
          return m-t[m][m];
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends