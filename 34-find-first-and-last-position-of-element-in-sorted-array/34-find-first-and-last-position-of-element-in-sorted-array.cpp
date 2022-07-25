class Solution {
public:
    
     int binaryS(vector<int>&nums,int target){
        
       int s=0,e=nums.size()-1,ans=-1;
         while(s<=e){
             int mid=s+(e-s)/2;
             if(nums[mid]==target){
                 ans=mid;
                 e=mid-1;
             }
             else if(nums[mid]<target){
                 s=mid+1;
             }
             else{
                 e=mid-1;
             }
             
         }
         
         return ans;
    }
    
    
    int binaryL(vector<int>&nums,int target){
        
        int s=0,e=nums.size()-1;
        
        int mid;
        int ans=-1;
       while(s<=e){
           int mid=s+(e-s)/2;
           
           if(nums[mid]==target){
               ans=mid;
               s=mid+1;
           }
           else if(nums[mid]<target){
               s=mid+1;
           }
           else
               e=mid-1;
           
       }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int lst=binaryL(nums,target);
        int strt= binaryS(nums,target);
         ans.push_back(strt);
        ans.push_back(lst);
       
        return ans;
        
    }
};