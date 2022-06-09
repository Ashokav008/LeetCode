class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>left(n);
        vector<int>right(n);
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(nums[i],mini);
            left[i]=mini;
            // cout<<left[i]<<" ";
        }
      // cout<<endl<<"Turn for right array"<<endl;
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi=max(nums[i],maxi);
            right[i]=maxi;
            // cout<<right[i]<<" ";
        }
    
        
        // cout<<endl<<"  ";
        for(int i=1;i<n-1;i++){
            // cout<<nums[i]<<" ";
            // cout<<left[i-1]<<"  "<<nums[i]<< " "<<right[i+1]<<endl;
            if(nums[i]>left[i-1] and nums[i]<right[i+1] and left[i-1]<right[i+1])
                    return true;
        }
        return false;
    }
};