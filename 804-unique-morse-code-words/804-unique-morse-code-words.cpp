class Solution {
public:
    vector<string>v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>st;
        for(auto it:words){
            string ans;
            for(int i=0;i<it.size();i++){
                ans+=v[it[i]-'a'];
            }
            st.insert(ans);
        }
    return st.size();        
    }
};