class Solution {

    int BS(int ele,int i, int j,int[] nums){

        int idx=-1;

        while(i<=j){
            int mid=(i+j)/2;
            if(ele<=nums[mid]){
                 i=mid+1;
                 idx=mid;
            }else if(ele>nums[mid]){
                j=mid-1;
            }else{
                i=mid+1;
            }

        }
        return idx;
    }

    public int maxDistance(int[] nums1, int[] nums2) {
        int n=nums1.length,m=nums2.length;
        int ans=Integer.MIN_VALUE;

        for(int i=0;i<n;i++){

            int currentAns=BS(nums1[i],i,m-1,nums2);
           
            if(currentAns!=-1)
                ans=Math.max(ans,currentAns-i);
            
            //  System.out.println("i:"+i+"currentAns:"+currentAns+"ans"+ans);

        }

        return ans==Integer.MIN_VALUE?0:ans;
        
    }
}