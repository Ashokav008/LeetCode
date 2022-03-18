class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int>lastIndex(26);
        int n=s.size();
        for(int i=0;i<n;i++)
            lastIndex[s[i]-'a']=i;
        
        
        stack<int>stk;
        vector<bool>seen(26,0);
        
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            
            if(seen[ch])
                    continue;
        while(!stk.empty() and stk.top()>ch  and i<lastIndex[stk.top()] )
        {
            seen[stk.top()]=false;
            stk.pop();
        }
            stk.push(ch);
            seen[ch]=true;
            
        }
        string ans;
        while(!stk.empty()){
            
            ans.push_back(char(stk.top()+'a'));
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        }
};