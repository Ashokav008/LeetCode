class Solution {
public:
    
    bool canSplit(int mid,vector<int>&nums,int m){
        
        int total=0;
        int cnt=1;
        for(auto it:nums){
            total+=it;
            if(total>mid){
                total=it;
                cnt++;
            }
            if(cnt>m)
                    return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
     
        int n=nums.size();
        int left=INT_MIN,right=0,mid;
        for(int i=0;i<n;i++){
            
            left=max(left,nums[i]);
            right+=nums[i];
        }
   
        while(left<right){
            mid=(left+right)/2;
            cout<<"mid "<<mid<<" "<<endl;
            if(canSplit(mid,nums,m)){
                right=mid;
            }
            else
                left=mid+1;
        }
        return left;
    }
};