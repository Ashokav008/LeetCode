class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       
        int sr=0,sc=0,er=n-1,ec=n-1;
        int cnt=1;
        vector<vector<int>>v(n,vector<int>(n,0));
        
        while(sr<=er and sc<=ec){
            
            for(int i=sc;i<=ec;i++){
                v[sr][i]=cnt++;
            }
            sr++;
            for(int i=sr;i<=er;i++){
                v[i][ec]=cnt++;
            }
            ec--;
            
            for(int i=ec;i>=sc;i--){
                v[er][i]=cnt++;
            }
            er--;
            
            for(int i=er;i>=sr;i--){
                v[i][sc]=cnt++;
            }
            sc++;
            
        }
        return v;
    }
};