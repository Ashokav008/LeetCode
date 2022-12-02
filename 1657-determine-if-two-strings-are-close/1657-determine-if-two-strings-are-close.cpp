class Solution {
public:
    bool closeStrings(string s1, string s2) {
        
        int n=s1.size(),m=s2.size();
        
        if(n!=m)
                return 0;
        
        vector<int>a(26,0),b(26,0);
        
        for(auto it:s1)
            a[it-'a']++;
        for(auto it: s2)
            b[it-'a']++;
        
        for(int i=0;i<26;i++){
            if((a[i]==0 and b[i] ) or (a[i] and b[i]==0))   return false;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
       for(int i=0;i<26;i++){
           
           if(a[i]!=b[i])
                return false;
           
       }
        
        return 1;
    }
};