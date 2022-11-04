class Solution {
public:
    
    int kadane(vector<int>&nums){
        int lcl=0,glbl=INT_MIN;
        int n=nums.size();
        int i=0;
        while(i<n){
            lcl+=nums[i];
            glbl=max(lcl,glbl);
            if(lcl<0)
                lcl=0;
            i++;
        }
        return glbl;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        
        int m1=kadane(nums);
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            nums[i]=-(nums[i]);
        }
        int m2=kadane(nums);
        cout<<m1<<"  "<<m2<<"   "<<sum<<endl;
        
        if(sum+m2==0)
                return m1;
        return max(m1, sum+m2);
    }
        
};