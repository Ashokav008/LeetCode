class Solution {
public:
       set<vector<int>>st;
    void solve(int index,vector<int>&ans,vector<int>&nums){
        
        st.insert(ans);
        for(int i=index;i<nums.size();i++){
            ans.push_back(nums[i]);
            solve(i+1,ans,nums);
            ans.pop_back();
        }
        return;
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
         int i=0;
        vector<vector<int>>final1;
        vector<int>ans;
        solve(i,ans,nums);
        for(auto i:st){
            final1.push_back(i);
        }
        
        return final1;
    }
};