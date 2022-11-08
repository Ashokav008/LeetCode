class Solution {
public:
    
    string makeGood(string s) {
       stack<char>stk;
        string ans;    
        for(int i=0;i<s.size();i++){
            if(!stk.empty() and ((stk.top()-'a'==s[i]-'A') or (stk.top()-'A'== s[i]-'a'))){
                stk.pop();
                if(ans.size())
                    ans.pop_back();
            }
          else{
                ans+=s[i];
                stk.push(s[i]);
            }
            
        }
        return ans;
    }
};