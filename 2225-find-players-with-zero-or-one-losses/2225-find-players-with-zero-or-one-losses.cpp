class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
         vector<vector<int>> ans;
        map<int,int>mp;
        sort(matches.begin(),matches.end());
        vector<int>oneLose,noLose;
        for(auto it: matches){
            mp[it[1]]++;
            
        }
        
        for(auto it: mp){
            if(it.second==1)
                oneLose.push_back(it.first);
        }
        
        for(auto it: matches){
            
            if(mp.find(it[0])==mp.end() ){
                    
                if(noLose.size()>0 and it[0]!=noLose.back())
                     noLose.push_back(it[0]);      
                
                else if(noLose.size()==0)
                    noLose.push_back(it[0]); 
             
                
            }
            
        }
        
        
        ans.push_back(noLose);
        ans.push_back(oneLose);
        
        return ans;
    }
};