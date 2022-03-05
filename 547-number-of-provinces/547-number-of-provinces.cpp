class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& v){
        v[i][j]=0;
        for(int k=0;k<v.size();k++){
            if(v[j][k]==1)
                dfs(j,k,v);
        }
    }
    
    int findCircleNum(vector<vector<int>>& v) {
        
        int nop=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(v[i][j]==1){
                    nop++;
                    dfs(i,j,v);
                }
            }
        }
        return nop;
    }
};