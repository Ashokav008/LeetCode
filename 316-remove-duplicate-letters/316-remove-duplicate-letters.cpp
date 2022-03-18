class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string ans;
        int n=s.size();
        vector<int>lastIndex(26);
        
        for(int i=0;i<n;i++)
            lastIndex[s[i]-'a']=i;
        
        stack<int>stk;
        vector<bool>seen(26,0);
        
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(seen[ch])
                continue;
            
            while(!stk.empty() and i<lastIndex[stk.top()] and stk.top()> ch){
                seen[stk.top()]=false;
                stk.pop();
                
            }
            stk.push(ch);
            seen[ch]=true;
        }
        while(!stk.empty()){
            ans.push_back(char(stk.top()+'a'));
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        
        
        return ans;
        
    }
};