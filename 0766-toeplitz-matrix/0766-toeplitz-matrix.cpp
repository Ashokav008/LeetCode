class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int i=n-1,j=0;
        
        while(i<n and j<m){
            int ele=mat[i][j];
            int i1=i-1,j1=j-1;
            while(i1>=0 and j1>=0){
                if(mat[i1][j1]!=ele)
                        return false;
                i1--;
                j1--;
            }
    
            j++;
        }
        cout<<endl<<endl;
        i=0,j=m-1;
        while(i<n-1){
            int i1=i-1,j1=j-1;
            int ele=mat[i][j];
            // cout<<ele<<endl;
            while(i1>=0 and j1>=0){
                
                if(mat[i1][j1]!=ele)
                        return false;
                i1--;
                j1--;
            }
            i++;
            
        }
        
        return true;
    }
};