class Solution {
    int ans=Integer.MAX_VALUE;

    int solve(int i, int j, int n, int m, int[][] grid, int[][] dp){
        if(i>=n || j>=m)
            return Integer.MAX_VALUE;
        if(i==n-1 && j==m-1)
            return grid[i][j];
      if(dp[i][j]!=-1)
        return dp[i][j];

      return  dp[i][j]= grid[i][j] + Math.min(solve(i+1,j,n,m,grid,dp),solve(i,j+1,n,m,grid,dp));
        //   System.out.println("i:"+i+"j:"+j +"value:"+grid[i][j]);
        //   return ans;
    }   

    public int minPathSum(int[][] grid) {
        int n=grid.length,m=grid[0].length;
        int[][] dp = new int[n+1][m+1];
         java.util.Arrays.fill(dp[0],Integer.MAX_VALUE);
        for(int i=0;i<=n;i++){
            // java.util.Arrays.fill(dp[i],Integer.MAX_VALUE);
            for(int j=0;j<=n;j++)
                dp[i][0]=Integer.MAX_VALUE;
        }
           
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=grid[i-1][j-1] + (Math.min(dp[i-1][j],dp[i][j-1])==Integer.MAX_VALUE?0:Math.min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n][m];
        // return solve(0,0,n,m,grid,dp);
    }
}