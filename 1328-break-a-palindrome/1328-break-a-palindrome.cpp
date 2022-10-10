class Solution {
public:
    string breakPalindrome(string str) {
        
        int n=str.size();
        if(n<=1)
                return "";
        map<char, int>mp;
        
        for(int i=0;i<n;i++){
            mp[str[i]]++;
        }
        if(mp.size()==1) //case for "aaaaaa"
        {
            if(str[0]=='a')
            {
                str[n-1]='b';
                return str;
            }
            else {
                str[0]='a';
                return str;
            }
        }
         //case for "aabaa"
        
        if(mp.size()==2){
            if(mp.begin()->second==1 or mp.rbegin()->second==1){
                
                    if(str[0]=='a'){
                        str[n-1]='b';
                        return str;
                    }
                else{
                    str[0]='a';
                    return str;
                }
                
            }
            
        }
    
        
        if(mp.size()==2)
        
        int i=0;
        for(int i=0;i<n;i++){
            
            if(str[i]!='a'){
                    str[i]='a';
                break;
            }
        }
        return str;
    }
};