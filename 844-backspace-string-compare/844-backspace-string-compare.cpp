class Solution {
public:
    string solve(string &s){
        string ans;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                if(ans.size()>0)
                ans.pop_back();
                
                
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    
    }
    
    bool backspaceCompare(string s, string t) {
        
       string ans1=solve(s);
        string ans2=solve(t);
        
     return (ans1==ans2);
        
    }
};