class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int a=INT_MAX,b=INT_MAX,n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]<a)
                a=nums[i];
            else if(a<nums[i] and nums[i]<b)
                b=nums[i];
            else if(a<nums[i] and b<nums[i])
                    return true;
        }
        return false;
        
    }
};