class Solution {
public:
    int maxProduct(vector<string> str) {
        
   int ans=INT_MIN;
        int n=str.size();
        vector<vector<int>>v(n,vector<int>(26,0));
      for(int i=0;i<n;i++){
          for(int j=0;j<str[i].size();j++){
              v[i][str[i][j]-'a']=1;
              
          }
       
      }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
              bool checked=true;
                for(int k=0;k<26;k++){
                if(  v[i][k]==1 and v[j][k]==1)
                {
                    checked=false;
                    break;
                }
                }
                
                    if(checked){
                        int curr=str[i].size()* str[j].size();
                        ans=max(ans,curr);
                    }
            }
        }
        if(ans<0)
                return 0;
        return ans;
    }
};