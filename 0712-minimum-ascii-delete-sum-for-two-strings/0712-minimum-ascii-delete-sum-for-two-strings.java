class Solution {
//   int lcs(String s1,String s2,int i, int j){
//     if(i<0 ||j<0)
//     return 0;

//     if(s1.charAt(i)==s2.charAt(j))
//         return 1+lcs(s1,s2,i-1,j-1);
//     return Math.max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
//   }


    public int minimumDeleteSum(String s1, String s2) {
        int n=s1.length(),m=s2.length();
         int dp[][]= new int[n+1][m+1];
      
        // return lcs(s1,s2,n-1,m-1);
        
         for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j]=s1.charAt(i-1)+dp[i-1][j-1];
                }
                else
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int total = 0;
        for (char c : s1.toCharArray()) total += c;
        for (char c : s2.toCharArray()) total += c;

        return total - 2 * dp[n][m];
    


    }
}