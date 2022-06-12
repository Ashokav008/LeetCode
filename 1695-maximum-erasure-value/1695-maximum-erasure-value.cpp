class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        int l=0,h=0;
        set<int>st;
        int ans=INT_MIN,curr=0;
        while(h<n){
            if(st.find(nums[h])==st.end()){
                // cout<<"pushing "<<nums[h]<<endl;
                st.insert(nums[h]);
                curr+=nums[h];
                ans=max(ans,curr);
                h++;
            }
            else{
                while(nums[l]!=nums[h]){
                    // cout<<"popping "<<nums[l]<<endl;
                    st.erase(nums[l]);
                    curr-=nums[l];
                    l++;
                }
                st.erase(nums[l]);
                 // cout<<"popping "<<nums[l]<<endl;
                curr-=nums[l];
                l++;
       
               
            }
        }
            return ans;
    }
};