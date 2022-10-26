class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>mp{{0,-1}};
        int curr=0;
        for(int i=0;i<n;i++){
          curr+=nums[i];
         int mod=  k==0 ? curr: curr%k;
            mp.insert({mod,i});
        if(i-mp[mod]>1)
                    return true;
            
        }
        return false;
    }
};