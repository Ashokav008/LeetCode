//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
    int solve(int n, int k, vector<int> &arr) {
       
       int sum=accumulate(arr.begin(),arr.end(),0);
       int ans=INT_MIN;
       vector<int>factor;
        for(int i=1;i<=sqrt(sum);i++){
            if(sum%i==0){
                factor.push_back(i);
                factor.push_back(sum/i);
            }
        }
       
       for(auto x:factor){
           int cnt=0;
           int sum=0;
          for(auto &y: arr){
              sum+=y;
              if(sum%x==0)
                cnt++;
          }
       if(cnt>=k)
            ans=max(ans,x);
       }
       
       return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends