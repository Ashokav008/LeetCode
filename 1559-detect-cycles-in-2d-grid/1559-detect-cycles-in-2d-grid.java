class Solution {
    int n,m;

    boolean dfs(char[][] grid,int[][] vis,int i,int j, char ch,int previ, int prevj){
        //   System.out.println("First :i:"+i+"j"+j+" "+"PrevI"+previ+"Prevj"+prevj);
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
                // System.out.println("Second - i:"+i+"j"+j+"  value"+grid[i][j]+" "+"PrevI"+previ+"Prevj"+prevj);

        if(grid[i][j]!=ch)
            return false;
        if(vis[i][j]==1)
            return true;    
        vis[i][j]=1;
        boolean a=false,b=a,c=a,d=a;


        if(!(i==previ && j+1==prevj)){
            // System.out.println("Going right");
            if(dfs(grid,vis,i,j+1,ch,i,j) )return true;
        }

        if(!(i+1==previ && j==prevj)){
            //   System.out.println("Going down");
              if( dfs(grid,vis,i+1,j,ch,i,j)) return true;
        }

        if(!(i-1==previ && j==prevj)){
            // System.out.println("Going up");

            if(dfs(grid,vis,i-1,j,ch,i,j)) return true;
        }
        if(!(i==previ && j-1==prevj)){
            // System.out.println("Going left");
            if(dfs(grid,vis,i,j-1,ch,i,j)) return true;
        }
        return false;
    }


    public boolean containsCycle(char[][] grid) {
        n=grid.length;m=grid[0].length;
       int[][] vis = new int[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int previ=-1,prevj=-1;
                if(vis[i][j]==0 && dfs(grid,vis,i,j,grid[i][j],previ,prevj))
                    return true;
            }
        } 

        return false;

    }
}