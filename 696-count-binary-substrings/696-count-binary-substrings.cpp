class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>ans;
        int n=s.size();
        int cnt=1;
        char ch=s[0];
        for(int i=1;i<n;i++){
           if(s[i]==ch){
               cnt++;
           }
           else{
                ans.push_back(cnt);
                cnt=1;
                ch=s[i];
            }
        }
        int f=0;
            ans.push_back(cnt);
        for(int i=1;i<ans.size();i++)
            f+=min(ans[i],ans[i-1]);
    
        return f;
    }
};