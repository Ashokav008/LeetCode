class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>ans;
      
        ans.push_back({1});
        for(int i=2;i<=n;i++){
            
            vector<int>v;
            vector<int>b=ans.back();
            int sz=b.size()-1;
            v.push_back(b[0]);
            int j=0;
            while(j<sz){
                v.push_back(b[j]+b[j+1]);
                j++;
            }
            v.push_back(b[sz]);
            ans.push_back(v);
        }
        return ans;
    }
};