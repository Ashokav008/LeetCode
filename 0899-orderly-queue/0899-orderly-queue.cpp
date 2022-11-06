class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n=s.size();
        string ans=s;
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        
        else{
            while(n--){
            
                s+=s[0];
                s.erase(0,1);
                cout<<s<<endl;
                ans=min(ans,s);
            }
        }
        return ans;
    }
};