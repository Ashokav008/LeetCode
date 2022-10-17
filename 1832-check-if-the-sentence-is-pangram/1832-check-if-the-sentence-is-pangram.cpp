class Solution {
public:
    bool checkIfPangram(string str) {
        int n=str.size();        
        vector<int>m(26,0);
        
        for(int i=0;i<n;i++){
           m[str[i]-'a']++;
        }
        for(auto it: m)
            if(it==0)
                    return 0;
        
        return true;
    }
};