class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n=nums.size();
           vector<int>left(n);
           map<int,int>right;
        
        int mini=INT_MAX;
            for(int i=0;i<n;i++){
               left[i]=min(nums[i],mini);
                mini=min(mini,nums[i]);
                if(i!=0)
                right[nums[i]]++;
            }
        
        for(int i=1;i<n-1;i++){
             if(right[nums[i]]<=1)
                    right.erase(nums[i]);
            else
                right[nums[i]]--;
            
            int b=nums[i];
            int a=left[i-1];
            auto it=right.upper_bound(a);
            
            if(it==right.end())
                continue;
            
           
            if(it->first<b and it->first<b){
                
                cout<<i<<"  "<<a<<b<<it->first<<endl;
                    return true;
            }
            
        }
        
        return false;
    }
};