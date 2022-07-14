class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
        
        if(needle.length()==0) return 0;
        
       if(haystack.find(needle)!=string::npos){
           return haystack.find(needle);
       }
        else
                return -1;
        int prime=31,mod=1000000007;
        int n_hash=0,h_hash=0;
        int start=0;
        int multiplier=0;
        for(int i=1;i<needle.length();i++){
            multiplier=(multiplier*prime)%mod;
        }
        for(int i=0;i<needle.size();i++){
            n_hash=(prime*n_hash+needle[i])%mod;
            h_hash=(prime*h_hash+haystack[i])%mod;
        }
        
        if(n_hash==h_hash)
            return 0;
        
        for(int i=needle.length();i<haystack.size();i++){
            
            
        }
    }
};