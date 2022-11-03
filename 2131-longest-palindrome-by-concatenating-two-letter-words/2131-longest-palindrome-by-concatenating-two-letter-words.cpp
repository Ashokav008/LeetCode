class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        map<string,int>mp;
        for(auto it:words)
                mp[it]++;
        int maxi=0,ans=0;
        bool flg=false;
        
        for(auto it:mp){
            string str=it.first;
            string rstr=str;
            reverse(str.begin(),str.end());
            if(str!=rstr and mp.find(str)!=mp.end() )
                    ans+=(2*min(mp[str],mp[rstr]));
            
            if(rstr==str  and mp[str]%2==0){
                ans+=2* mp[str];
            }
            else if(rstr==str and mp[str]%2==1)
            {
                flg=true;
                ans+=2*(mp[str]-1);
            }
                
                
            
        }
        if(flg) 
                ans+=2;
        
        return ans;
        
    }
};