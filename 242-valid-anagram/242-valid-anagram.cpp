class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        n=t.size();
        for(int i=0;i<n;i++){
            if(mp.find(t[i])!=mp.end() and mp[t[i]]!=0){
                
                mp[t[i]]--;
                
                
            }else
                    return 0;
                
            
        }
        for(auto it:mp){
            if(it.second>0)
                    return 0;
            
        }
        return 1;
    }
};