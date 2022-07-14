class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     
        int lcl=0,glbl=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            lcl+=nums[i];
            
            glbl=max(lcl,glbl);
            if(lcl<0){
                
                lcl=0;
            }
            
              
        }
        
        return glbl;
        
    }
};