class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>mp(60,0);
        int n=time.size();
        for(int i=0;i<n;i++){
            int ele=(time[i]%60);
            mp[ele]+=1;
            // cout<<mp[ele]<<endl;
            
        }
        long long cnt=0;
        int j=59,i=1;
    
      cnt+=((mp[30]-1)*mp[30])/2;
       while(i<30){
           
           
           
           cnt+=((mp[i])*mp[60-i]);
           
   
           i++;
       }
        
      long  z = (long (mp[0]-1)*mp[0])/2;
        cnt+=z;
        return cnt;
        
    }
};