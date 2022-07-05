class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>st;
        int n=nums.size();
        if(n==0 or n==1)
                return n;
        for(auto &it:nums)
            st.insert(it);
        
        
        int prev=-1;
        int i=0;
        int maxi=0;
        int lcl=0;
        for(auto &it:st){
            if(i==0){
              
                i++;
                
            }
       else if(abs(it-prev)==1){
            lcl++;
            maxi=max(maxi,lcl);
        }
        
    else
        lcl=0;
      
      prev=it;
        }
    return maxi+1;
        
    }
};