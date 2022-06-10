class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans=0;
        int start=0;
        unordered_map<char,int>mp;
        int n=s.size();
        if(n==1 or n==0)
            return n;
                
        
        for(int i=0;i<n;i++){
            
            if(mp.find(s[i])!=mp.end()  and mp[s[i]]>=start)
                start=mp[s[i]]+1;
            
            
            ans=max(ans,i-start+1);
            mp[s[i]]=i;
        }
         if(ans==0)
                return n;
        return ans;
    }
};