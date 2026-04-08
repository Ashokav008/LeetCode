class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        int ans=0;
        long MOD = 1_000_000_007L;
        for(int [] query:queries){
            int i1=query[0],n=query[1],k=query[2],v=query[3];
            for( int i=i1;i<=n;i+=k){
                nums[i]=(int)((nums[i]%MOD*v)%MOD);
            }
            
        }
        ans=nums[0];
        for(int i=1;i<nums.length;i++){
            System.out.println(nums[i]);
            ans^=nums[i];
        }
        return ans;

    }       
}