class Solution {
public:
    void solve(int index,int n,vector<int>& nums,vector<vector<int>>&ans){
        
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j=index;j<nums.size();j++){
            swap(nums[j],nums[index]);
            solve(index+1,n,nums,ans);
             swap(nums[j],nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int i=0;
        int n=nums.size();
        vector<vector<int>>ans;
        solve(i,n,nums,ans);
        return ans;
    }
};