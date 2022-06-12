class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
      
       int sum=accumulate(nums.begin(),nums.end(),0);
        int s=0,e=0,currSum=0;
        int ans=INT_MAX;
        if(sum<x)
                return -1;
        
        // cout<<sum<<enl;
        while(e<n){
            currSum+=nums[e];
            
            while(currSum>(sum-x)){
                currSum-=nums[s++];
            }
            if(currSum==(sum-x)){
                ans=min(ans,n-(e-s+1));
               
            }
               e++;     
            
        }
        
        return ans==INT_MAX?-1:ans;
    }
};