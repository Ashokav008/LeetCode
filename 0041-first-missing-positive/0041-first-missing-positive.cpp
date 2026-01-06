class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        st.insert(nums[i]);
        int i=1;
        while(i){
            if(st.find(i)==st.end())
                return i;
            i++;
        }

        return i+1;
    }
};