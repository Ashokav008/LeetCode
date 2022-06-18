class Solution {
public:
    
    void dfs(vector<vector<int>>& image,int i,int j,int color,int f){
        if( i<0 or j<0 or i>=image.size() or j>=image[0].size() or  image[i][j]==color or image[i][j]!=f)
                return;
        
        image[i][j]=color;
        
        dfs(image,i+1,j,color,f);
         dfs(image,i-1,j,color,f);
         dfs(image,i,j+1,color,f);
         dfs(image,i,j-1,color,f);
        
        
    }
    
vector<vector<int>>floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
    int fcolor=image[sr][sc];
        if(image[sr][sc]==color)
                return image;
         dfs(image,sr,sc,color,fcolor);

        
        return image;
    }
};