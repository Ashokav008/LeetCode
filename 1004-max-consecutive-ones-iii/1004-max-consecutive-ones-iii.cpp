class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l=0,zeros=0,i=0;
        int ans=INT_MIN;
        int n=nums.size();
        while(i<n){
           if(nums[i]==0)
                zeros++;
            
               while(zeros>k){
                   if(nums[l]==0)
                        zeros--;
                   
                   l++;
               }
            
            ans=max(ans,i-l+1);
            i++;
        }
        return ans;
        
    }
};