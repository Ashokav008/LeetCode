class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n=s.size();
        int i=0;
        reverse(s.begin(),s.end());
        
        while(i<n){
            string str;
            while(i<n and s[i]!=' ')
                    str+=s[i++];
            if(str.size()>0){
            reverse(str.begin(),str.end());
            ans+=str+" ";
            }
            while(i<n and s[i]==' ')
                i++;
            
        }   
        
        ans.pop_back();
        cout<<ans<<endl;
        
        return ans;
    }
};