class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      
            unordered_map<int,int>mp;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int f=k-nums[i];
            if(mp.find(f)!=mp.end() and mp[f]!=0 ){
                    cnt++;
             mp[f]--;
            }
            else
                mp[nums[i]]++;
            
        }
        
        return cnt;
    }
};