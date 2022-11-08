class Solution {
public:
    bool solve(string &s){
        
        
        
        
       bool flg=true;
        for(int i=0;i<s.size()-1;i++){
                if((s[i]-'a' == s[i+1]-'A') or ( s[i]-'A'==s[i+1]-'a')){
                        flg=false;
                        s.erase(i,2);
                        i-=2;
                    
                }
            
        }
        return flg;
        
    }
    
    string makeGood(string s) {
        
        
        while(1){
            if(s.size()<2)
                    break;
            
            if(solve(s))
                    break;
        }
        
        return s;
        
    }
};