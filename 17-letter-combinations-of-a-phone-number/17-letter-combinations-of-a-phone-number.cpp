class Solution {
public:
    
    void solve(int index,string str,string &digits,vector<string>&ans,string mapping []){
        if(index >= digits.length()){
            ans.push_back(str);
            return;
        }
        int number=digits [index] -'0';
        string value=mapping[number];
        for(int i=0;i<value.length();++i){
            str.push_back(value[i]);
            solve(index+1,str,digits,ans,mapping);
            str.pop_back();
        }
        
   
    } 
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string str="";
        if(digits.size()==0)
        return ans;
        int index=0;
        string mapping[10]=     {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(index, str, digits, ans, mapping);
        return ans;
    }
};