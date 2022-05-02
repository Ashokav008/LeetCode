class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
         int n=nums.size();
        vector<int>ans(n);
        int i1=0,j=n-1;
       
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[i1]=nums[i];
                i1++;
            }
            else{
                ans[j]=nums[i];
                j--;
            }
        }
        return ans;
    }
};