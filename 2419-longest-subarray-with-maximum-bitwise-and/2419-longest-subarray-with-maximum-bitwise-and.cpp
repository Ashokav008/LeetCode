class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       
        int maxi=INT_MIN,n=nums.size();
        for(auto it:nums){
           maxi=max(maxi,it);
       }
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi)
                    cnt++;
            else{
                cnt=0;
            }
            ans=max(ans,cnt);
        }
        
        
        return ans;
    }
};