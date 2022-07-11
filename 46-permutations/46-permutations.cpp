class Solution {
public:
    void solve(int index,int n,vector<int>&nums, vector<vector<int>>&ans){
        if(index>=n){
        ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            solve(index+1,n,nums,ans);
            swap(nums[i],nums[index]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        int n=nums.size(),i=0;
        solve(i,n,nums,ans);
        return ans;
        
    }
};