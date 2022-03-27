class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int sum;
        vector<pair<int,int>> v;
        for(int i=0;i<mat.size();i++)
        {
            sum = 0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    sum+=1;
            }
            v.push_back({sum,i});
        }
        sort(v.begin(),v.end());
        vector<int> ans;        
        for(auto i=v.begin();i!=v.end();i++)
        {
            if(k==0)
                break;
            ans.push_back((*i).second);
            k--;
        }  
        return ans; 
    }
};