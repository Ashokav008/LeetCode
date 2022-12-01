class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++){
            
            if(i<n/2 and st.find(s[i])!=st.end()){
                cnt++;
            }
            else if(st.find(s[i])!=st.end() and i>=n/2){
                cnt--;
            }
        }
        return cnt==0?1:0;
    }
};