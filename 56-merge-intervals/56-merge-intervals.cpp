class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        
        vector<vector<int>>ans;
        
        sort(arr.begin(),arr.end());
        
        for(auto interval:arr){
            if(ans.empty() or ans.back()[1]<interval[0]){
                ans.push_back(interval);
            }
            else{
                ans.back()[1]=max(ans.back()[1],interval[1]);
            }
            
        }
        
        return ans;
    }
};