class Solution {
public:
    
     int binary(vector<int>&nums,int target,string pos){
        
       int s=0,e=nums.size()-1,ans=-1;
         while(s<=e){
             int mid=s+(e-s)/2;
             if(nums[mid]==target){
                   ans=mid;
                 
                 if(pos=="s"){
                    e=mid-1;
                 }
                 else
                   s=mid+1;  
                
                
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
    
    
//     int binaryL(vector<int>&nums,int target){
        
//         int s=0,e=nums.size()-1;
        
//         int mid;
//         int ans=-1;
//        while(s<=e){
//            int mid=s+(e-s)/2;
           
//            if(nums[mid]==target){
//                ans=mid;
//                s=mid+1;
//            }
//            else if(nums[mid]<target){
//                s=mid+1;
//            }
//            else
//                e=mid-1;
           
//        }
    //     return ans;
    // }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int lst=binary(nums,target,"l");
        int strt= binary(nums,target,"s");
         ans.push_back(strt);
        ans.push_back(lst);
       
        return ans;
        
    }
};