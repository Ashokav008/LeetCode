class Solution {
public:
    vector<string>ans;
    void solve(string digits,int i,int n,vector<string>&mapping,string &curr){
        
        
         if(curr.size()==n){
                ans.push_back(curr);
            return;
        }
        
        // int digit=digits[i]-'0';
        
        // string map=mapping[digit];
        
        for(int  j=i;j<digits.size();j++){
            int num=digits[j]-'0';
            // cout<<endl<<num<<endl;
           for(auto it:mapping[num])
           {
               // cout<<it<<'  ';
               curr.push_back(it);
               solve(digits,j+1,n,mapping,curr);
               curr.pop_back();
           }
            
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
       
        vector<string>mapping{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n=digits.size();
        ans.clear();
        if(n==0)
        {
            // ans.push_back({""});
            return ans;
        }
        string curr="";
        solve(digits,0,n,mapping,curr);
        return ans;
    }
};