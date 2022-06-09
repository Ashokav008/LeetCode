class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
     
      
         set<vector<int>>st; 
       vector<vector<int>>ans;
        if(nums.size()<3)
                return ans;
        
        map<int,int>mp;
        for(int i=0;i<n-2;i++){
            
            if(mp.find(nums[i])==mp.end()){
               
                int j=i+1,k=n-1;
                
                while(j<k){
                    if(nums[i]+nums[j]+nums[k]==0){
                      st.insert({nums[i],nums[j],nums[k]});
                        j++;k--;
                    }
                    else if(nums[i]+nums[j]+nums[k]>0)
                        k--;
                    else
                        j++;
                }
                
            }
            mp[nums[i]]++;
        }
        
     for(auto i:st){
         ans.push_back(i);
     }
        return ans;
    }
};