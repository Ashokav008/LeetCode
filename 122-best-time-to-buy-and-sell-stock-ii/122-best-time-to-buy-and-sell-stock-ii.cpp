class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        
        int ret=0;
        int n=p.size();                            
     for(int i=1;i<n;i++){
         if(p[i]>p[i-1])
                ret+=p[i]-p[i-1];
         
     }
          return ret;                         
        
    }
};