class Solution {
public:
    bool areOccurrencesEqual(string str) {
        map<char,int>mp;
        for(auto it: str){
            mp[it]++;
        }
        
        int acnt=mp[str[0]];
        
        for(auto it:mp){
            if(it.second!=acnt)
                    return false;
        }
        
        return true;
    }
};