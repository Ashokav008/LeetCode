class Solution {
public:


    
    int subarraySum(vector<int>& arr, int k) {
        int  sum=0,ans=0;
        unordered_map<int,int>mp;
       
        mp[0]=1;
        for(auto ele:arr){
            sum+=ele;
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
           
            
            mp[sum]++;
        }
        return ans;
    }
};