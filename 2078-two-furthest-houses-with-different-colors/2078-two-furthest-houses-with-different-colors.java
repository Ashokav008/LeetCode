class Solution {
    public int maxDistance(int[] arr) {
        int i=0,j=arr.length-1,n=j;
        while(arr[i]==arr[j]){
            j--;
        }
        int ans=j-i;
        i=0;j=n;
        while(arr[i]==arr[j]){
            i++;
        }
        // System.out.println("i"+i+"j"+j+ "diff"+(j-i));

        ans=Math.max(ans,j-i);
        return ans;
    }
}