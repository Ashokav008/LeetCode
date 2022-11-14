class Solution {
public:
    vector<int>par,rank;
    
    int findPar(int x)
    {
        if(x==par[x])
            return x;
        
        return par[x]=findPar(par[x]);
        
    }
    
    void unionDSU(int a, int b){
        int x=findPar(a);
        int y=findPar(b);
        if(x==y)    return;
        
        if(rank[x]<rank[y]) 
                par[x]=y;
        else if(rank[x]>rank[y])
                par[y]=x;
        else{
            par[x]=y;
            rank[y]++;
        }
        
    }
    
    int removeStones(vector<vector<int>>& stones) {
      
        int n=stones.size();
        par.resize(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        
        rank.resize(n,1);
        
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
              if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                    unionDSU(i,j);
          }  
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
                if(par[i]==i)
                        cnt++;
        return n-cnt;
    }
};