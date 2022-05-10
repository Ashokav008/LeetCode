class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
    
        unordered_map<char,int>mp;
        int start=0,ans=INT_MIN;
        int n=s.size();
        if(n==0 or n==1)
                return n;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end() and mp[s[i]]>=start)
                start=mp[s[i]]+1;
            
              mp[s[i]]=i;
              ans=max(ans,i-start+1);
            
        }
        return ans;
    }
};