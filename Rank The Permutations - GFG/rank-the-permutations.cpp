// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  vector<long long>fact1;
  
  void fact()
  {
      int i=0 ;
      long long f=1;
      while(i<20)
      {
          f=f*(i+1);
          fact1.push_back(f);
        //   cout<<f<<" ";
          i++;
      }
    
  }
  
  
  
 long long ans=0;
//   int cnt=0;
  void rec(string str)
  {
     
    
     if(str.size()==2){
         
         if(str[0]<str[1])
         ans++;
         else
          ans+=2;
          
          return;
     }
     string req = str ;
     sort(req.begin(), req.end()) ;
     int pos;
    //  cout<<str<<"   "<<req<<endl;
     for(int i=0;i<req.size();i++)
     {
         if(str[0]==req[i]){
             pos=i+1;
             break;
         }
         
     }
     
        // cout<<" pos is "<<pos<<endl;
     pos--;

    long long n= str.size() ;
    long long g = (fact1[n-1]/n)*pos ;
    // cout<<g<<" "<<endl;
    ans+=g ;
    str.erase(0,1);
    
    // cout<<str<<endl;
     rec(str) ;
    
  }
  
    long long findRank(string str) {
        string req = str ;
        // sort(req.begin(), str.end()) ; //bedac
        if(str.size()==1)
        return 1; 
        
        long long f =1 ;
        int n=str.size(); 
        fact();
        rec(str) ;
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends