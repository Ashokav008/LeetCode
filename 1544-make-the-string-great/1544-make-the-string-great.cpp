class Solution {
public:
    
    string makeGood(string s) {
        
       stack<char>stk;
        
        string ans;    //leEeetcode
        
        for(int i=0;i<s.size();i++){
            
          bool flg=true;
            if(!stk.empty() and ((stk.top()-'a'==s[i]-'A') or (stk.top()-'A'== s[i]-'a'))){
                stk.pop();
                  cout<<" removing "<<s[i]<<endl;
                if(ans.size())
                    ans.pop_back();
                flg=false;
                
            }
            
           if(flg){
               cout<<" adding "<<s[i]<<endl;
                ans+=s[i];
                stk.push(s[i]);
            }
            
        }
        return ans;
    }
};