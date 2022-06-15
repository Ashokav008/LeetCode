class Solution {
public:
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
     map<string,int>mp;
    sort(words.begin(),words.end(),comp);        
        
        
        // int n=v.size();
        int len=0;
        for(auto word:words){
            mp[word]=1;
            for(int i=0;i<word.size();i++){
                
                string s=word.substr(0,i)+word.substr(i+1);
                
                if(mp.find(s)!=mp.end()){
                        mp[word]=mp[s]+1;
                }
                
                
                len=max(len,mp[word]);
                // mp[word]=word.size();
            }
            
        }
        return len;
    }
};