class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        
        int n=arr.size();
        if(n<=2)
                return 0;
        
        int ans=0;
       int prev=INT_MIN;
        int series=0;
        for(int i=1;i<n-1;i++){
            int curr=arr[i]-arr[i-1];
            if(arr[i]-arr[i-1]==arr[i+1]-arr[i]){      
                ans++;              
                cout<<arr[i]<<" "<<endl;
              if(curr==prev){
                 series++;
                  ans+=series;
                  cout<<"Added Series  "<<series<<"  "<<arr[i]<<endl;
                  
              }
              
             prev=curr;
        }
         else{
                  prev=INT_MIN;
                  series=0;
                  cout<<"set Series as 0"<<" "<<arr[i]<<endl;
            } 
            
            
      }
        return ans;
    }
};