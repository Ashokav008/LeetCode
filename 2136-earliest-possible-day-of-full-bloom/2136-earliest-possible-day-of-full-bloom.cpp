class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int n=pt.size(),days=0;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({gt[i],pt[i]});
        }
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        
        int ans=0;
        for(auto it:vp){
            
            days+=it.second;
            ans=max(ans, days+it.first);
        }
        
        return ans;
    }
};