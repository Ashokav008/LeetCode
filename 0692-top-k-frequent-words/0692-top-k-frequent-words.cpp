class Solution {
public:
    static bool comp(pair<int,string> &p1 , pair<int,string>&p2){
        
        if(p1.first>p2.first)
            return true;
        else if(p1.first==p2.first){
            return p1.second<p2.second;
            
            
        }
        
        return false;
        
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
       map<string,int>mp;
        vector<string >ans;
        for(auto it: words){
            // cout<<it<<endl;
            mp[it]++;
        }
        
        vector<pair<int,string>>vp;
        for(auto it: mp){
           vp.push_back({it.second,it.first});
        }
        
        sort(vp.begin(),vp.end(),comp);
        int i=0;
         while(i<k){
             ans.push_back(vp[i].second);
             i++;
         }
        return ans;
    }
};