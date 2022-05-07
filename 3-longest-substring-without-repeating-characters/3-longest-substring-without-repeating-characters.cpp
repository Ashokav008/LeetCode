class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        if(s=="")
                return 0;
        int i=0,j=0,len=INT_MIN;
        
        while(j<n){
            if(mp[s[j]]>0){
                // cout<<s[i]<<endl;
                mp[s[i]]--;
                i++;
            }
            else if(mp[s[j]]==0){
                mp[s[j]]++;
                j++;
                len=max(len,j-i);
                
            }
        }
        return len;
    }
};