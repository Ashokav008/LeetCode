class Solution {
public:
int pivot(vector<int>array,int size){
        
    int left = 0;
    int right = size - 1;
    while(left < right) 
    {
        if(array[left] < array[right]) // case 1
           return left;
        int mid = left + (right-left)/2;
        
        if(array[mid] > array[right])
           left = mid + 1;      // case 2
        else
           right = mid;            // case 3
    }
return left;
    }
    
    
    int BS(int low,int high,int target,vector<int>& nums){
        int ans=-1;
    int mid=low+(high-low)/2;
        while(low<=high){
            
            
            
            if(nums[mid]==target)
            {
                // ans=mid;
                    return mid;
            }
            
            else if(nums[mid]>target){
                high=mid-1;
            }
            else
                low=mid+1;
            
             mid=low+(high-low)/2;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int ans=-1,n=nums.size();
        if(nums[0]<nums[n-1])
            return BS(0,n-1,target,nums);
        
        
        int pvt=pivot(nums,n);
        int l=BS(0,pvt,target,nums);
        int r=BS(pvt,n-1,target,nums);
        if(l==-1 and r==-1)
            return -1;
        // cout<<l<<"  "<<r<<endl;
        if(l==-1)
                return r;
    
        return l;
     // return 0;
    }
};