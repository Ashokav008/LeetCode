class Solution {
public:
    vector<string>ans;
    void solve(int open , int close, int n, string str){
        
        if(open>n or close>n)
                return;
        if(close> open)
                return;
        
        if(open==n and close==n){
                ans.push_back(str);
            return;
        }
        solve(open+1, close, n, str+'(');
        
        if(open>close){
            solve(open, close+1, n , str+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        
        return ans;
    }
};